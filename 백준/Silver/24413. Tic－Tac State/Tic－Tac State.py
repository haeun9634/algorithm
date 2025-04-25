WIN_PATTERNS = [
    [0, 1, 2], [3, 4, 5], [6, 7, 8],  # 가로
    [0, 3, 6], [1, 4, 7], [2, 5, 8],  # 세로
    [0, 4, 8], [2, 4, 6]              # 대각선
]

def parse_game_state(octal_str):
    state = int(octal_str, 8)
    bits = bin(state)[2:].zfill(32)

    played = bits[-9:]       # bits 0~8
    owners = bits[-18:-9]    # bits 9~17
    # next_turn = bits[-19]  # bit 18 (필요하지 않음)

    board = [' ']*9
    for i in range(9):
        if played[8-i] == '1':
            board[i] = 'X' if owners[8-i] == '1' else 'O'
    return board

def check_winner(board):
    for pattern in WIN_PATTERNS:
        a, b, c = pattern
        if board[a] != ' ' and board[a] == board[b] == board[c]:
            return board[a] + " wins"
    if ' ' in board:
        return "In progress"
    return "Cat's"

def main():
    c = int(input())
    for _ in range(c):
        octal_input = input().strip()
        board = parse_game_state(octal_input)
        print(check_winner(board))

if __name__ == "__main__":
    main()
