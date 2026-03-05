import customtkinter as ctk
from itertools import permutations

class TicTacToeBoard(ctk.CTk):
    def __init__(self, game_logic):
        super().__init__()
        # --- UI Initialization ---
        ctk.set_appearance_mode("dark")
        ctk.set_default_color_theme("dark-blue")
        self.title("Tic Tac Toe by weng")

        # --- Window Centering Logic ---
        # Calculates the center of the user's specific screen to place the window perfectly.
        self.width, self.height = 400, 470
        screen_width, screen_height = self.winfo_screenwidth(), self.winfo_screenheight()
        x, y = (screen_width/2) - (self.width/2), (screen_height/2) - (self.height/2)
        self.geometry('%dx%d+%d+%d' % (self.width, self.height, x, y))

        # --- Game State ---
        self.count = 1  # Turn counter: Odd numbers = Player 1, Even = Player 2
        self.logic = game_logic
        
        # --- Board Mapping ---
        # Maps IDs (1-9) to Grid Coordinates (Row, Column). 
        # This allows the logic to use simple integers while the UI knows where to draw.
        self.board_positions = {
            1: (0, 0), 2: (0, 1), 3: (0, 2),
            4: (1, 0), 5: (1, 1), 6: (1, 2),
            7: (2, 0), 8: (2, 1), 9: (2, 2),
        }
        self.display_buttons = [] # Stores button objects for easy access/clearing
        
        self.display_box() # Header/Status display
        self.draw_board()  # The 3x3 clickable grid
        self.reset_button() # The utility button to restart
    
    def display_box(self):
        """Creates the status bar at the top (e.g., 'Get Ready', 'X Wins')."""
        display_frame = ctk.CTkFrame(master=self, border_width=1, border_color="orange")
        display_frame.pack(padx=10, pady=20)
        self.display = ctk.CTkLabel(
            master=display_frame,
            text="Get Ready",
            corner_radius=20,
            font=ctk.CTkFont("INK FREE", 30, "normal")
        )
        self.display.pack()

    def draw_board(self):
        """Generates the buttons. Uses a lambda 'capture' to assign IDs to buttons."""
        grid_frame = ctk.CTkFrame(master=self)
        grid_frame.pack()

        self.grid_rowconfigure(0, weight=1)
        self.grid_columnconfigure((0, 1), weight=1)
        
        for key, value in self.board_positions.items():
            # LAMBDA EXPLANATION: 'pos=key' is a 'default argument'.
            # It freezes the current value of 'key' into the button's command.
            # Without it, every button would think it was the last number in the loop (9).
            button = ctk.CTkButton(
                master=grid_frame, text='', width=100, height=100, corner_radius=5,
                hover_color="lightblue", font=ctk.CTkFont("Mv Boli", 36, "bold"),
                command=lambda pos=key: self.update_board(pos)
            )
            button.grid(row=value[0], column=value[1], padx=5, pady=5, sticky="nsew")
            self.display_buttons.append(button)

    def reset_button(self):
        """Creates the 'RESET' button in the UI."""
        button = ctk.CTkButton(
            master=self, text="RESET", corner_radius=5, hover_color="red",
            command=self.reset_board, font=ctk.CTkFont("Mv Boli", 20, "bold")
        )
        button.pack(anchor=ctk.NE, pady=10, padx=10)
        
    def update_board(self, position):
        """Processes a click on a board square."""
        # Determine who is clicking based on the turn count
        index = 1 if self.count % 2 != 0 else 2
        player = f'player_{index}'
        
        # VALIDATION: Check the logic's 'move_history' (move log) to see if square is taken
        if position in self.logic.move_history:
            self.display.configure(text="MOVE HAS BEEN MADE", text_color="white")
        else:
            # RECORD MOVE: Add to history and update button visuals
            self.logic.move_history.append(position)
            self.display_buttons[position-1].configure(
                text=self.logic.marker[player],
                text_color=self.logic.color[player],
                hover_color='black'
            )
            
            # TERMINAL STATE CHECK: Is the game over (Win or Tie)?
            if self.game_still_on(player):
                self.display.configure(text=self.logic.player[player]+" played", text_color=self.logic.color[player])
            else:
                # BOARD LOCK: If game ends, fill the history with [1,2,3,4,5,6,7,8,9].
                # This makes the 'if position in move_history' check fail for all future clicks.
                self.logic.move_history = [i for i in range(1, 10)]
            self.count += 1
        
    def game_still_on(self, player):
        """Checks for winners or a full board."""
        if self.logic.player_has_won(player):
            self.display.configure(text=self.logic.player[player]+" WINS", text_color="green")
            return False
            
        # MATHEMATICAL TIE CHECK:
        # Sum of 1 through 9 is 45. If the sum of moves reaches this, the board is full.
        if sum(self.logic.move_history) >= sum([i for i in range(1, 10)]):
            self.display.configure(text="ENDS IN A TIE", text_color="red")
            return False
        return True

    def reset_board(self):
        """Wipes the UI and resets the logic class."""
        self.logic.reset_logic()
        self.count = 1
        self.display.configure(text="Get Ready", text_color="green")
        for button in self.display_buttons:
            button.configure(hover_color="lightblue", text="")
            
        
class TicTacToeLogic:
    def __init__(self, player_1 = 'player_1', player_2='weng'):
        self.player = {'player_1': player_1, 'player_2': player_2}
        self.marker = {'player_1': 'X', 'player_2': 'O'}
        self.color = {'player_1': 'yellow', 'player_2': 'brown'}
        self.move_history = [] # A chronological log of every move made
        self.current_player_moves = []   # Temporary list used to check for win patterns

    def __get_player_moves(self, move_history, player):
        """Sifts through the move log to pull out only one player's moves."""
        for i, j in enumerate(move_history):
            # Player 1 is indices 0, 2, 4... | Player 2 is indices 1, 3, 5...
            if i % 2 == 0 and player == 'player_1':
                self.current_player_moves.append(j)
            if i % 2 != 0 and player == 'player_2':
                self.current_player_moves.append(j)
             
    def player_has_won(self, player):
        # Get the player's moves as a SET of strings
        self.__get_player_moves(self.move_history, player)
        player_moves = set(map(str, self.current_player_moves)) # e.g., {'1', '5', '2', '3'}
        
        # The 8 winning sequences (also as sets)
        possible_wins = [
            {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}, # Rows
            {'1', '4', '7'}, {'2', '5', '8'}, {'3', '6', '9'}, # Cols
            {'1', '5', '9'}, {'3', '5', '7'}                  # Diagonals
        ]

        # Check if any win set is a "subset" of player moves
        for win_combo in possible_wins:
            if win_combo.issubset(player_moves):
                self.current_player_moves.clear()
                return True
                
        self.current_player_moves.clear()
        return False
    
    def reset_logic(self):
        """Clears the history for a new game."""
        self.current_player_moves.clear()
        self.move_history.clear()

def main():
    game_logic = TicTacToeLogic()
    board = TicTacToeBoard(game_logic)
    board.mainloop()

if __name__=="__main__":
    main()
