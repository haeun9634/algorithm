import sys
sys.setrecursionlimit(10000)

def input_board():
    board = []
    for _ in range(9):
        line = input().strip()
        row = [int(ch) for ch in line]
        board.append(row)
    return board

def print_board(board):
    for row in board:
        # 각 행의 숫자를 이어붙여 출력
        print("".join(map(str, row)))

def check_rule(board, r, c):
    # 행, 열 검사
    for i in range(9):
        if i != c and board[r][c] == board[r][i]:
            return False
        if i != r and board[r][c] == board[i][c]:
            return False

    # 3x3 박스 검사
    sr = (r // 3) * 3
    sc = (c // 3) * 3
    for i in range(sr, sr + 3):
        for j in range(sc, sc + 3):
            if i == r and j == c:
                continue
            if board[r][c] == board[i][j]:
                return False
    return True

def solve(board, r, c):
    if r == 9:
        print_board(board)
        sys.exit(0)  # 해답을 찾으면 프로그램 종료
    if c == 9:
        solve(board, r + 1, 0)
        return
    if board[r][c] == 0:
        for num in range(1, 10):
            board[r][c] = num
            if check_rule(board, r, c):
                solve(board, r, c + 1)
        board[r][c] = 0  # 모든 숫자 시도 후에도 해답이 없으면 원상 복귀
    else:
        solve(board, r, c + 1)

def main():
    board = input_board()
    solve(board, 0, 0)

if __name__ == "__main__":
    main()
