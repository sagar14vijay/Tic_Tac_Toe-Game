import sys
    
def main(): #Exercise 27 - Tic Tac Toe Draw - collect player input and draw the board each turn.
    def show_board(game_state):
        print ''
        for row in game_state:
            print [icon(square) for square in row]
    
    def swap_turn(player_number):
        if player_number==1:
            return 2
        elif player_number==2:
            return 1
    
    def icon(player_number):
        if player_number==1:
            return 'O'
        elif player_number==2:
            return 'X'
        else:
            return ' '
            
    def check_win(game,w):
        win=False
        if game[0]==[w,w,w] or game[1]==[w,w,w] or game[2]==[w,w,w]:
            win=True
        elif game[0][0]==w and game[1][0]==w and game[2][0]==w:
            win=True
        elif game[0][1]==w and game[1][1]==w and game[2][1]==w:
            win=True
        elif game[0][2]==w and game[1][2]==w and game[2][2]==w:
            win=True
        elif game[0][0]==w and game[1][1]==w and game[2][2]==w:
            win=True
        elif game[0][2]==w and game[1][1]==w and game[2][0]==w:
            win=True
        return win

    print '***********************'
    print 'Welcome to Tic Tac Toe Game!'
    print '***********************'
    print 'in turns please enter your desired move coordinates in the following format:'
    print 'row,column'
    print 'For example:- To mark the top right square, enter: 1,3\n'

    #config:
    start_state=[[' ',' ',' '],[' ',' ',' '],[' ',' ',' ']]
    starting_player=1

    whos_turn=starting_player
    game_state=[list(row) for row in start_state]
    game_on=True

    while game_on==True:
        try:
            move=[int(value)-1 for value in raw_input('player %d (%s), make your move [row,col]: ' % (whos_turn,icon(whos_turn))).split(',')]
            if game_state[move[0]][move[1]]==' ':     
                game_state[move[0]][move[1]]=whos_turn
                show_board(game_state)
                if check_win(game_state,whos_turn)==True:
                    game_on=False
                    print '************************'
                    print 'game over! player %d won!' % whos_turn
                    print '************************'
                whos_turn=swap_turn(whos_turn)
            else:
                print 'illegal move. please try another sqaure.'
        
        except ValueError:
            print '\nError. Please enter your move with the correct format:'
            print 'row,column'
            print 'for example to mark the top right square, enter: 1,3\n'
        
        full_squares=0
        for square in game_state[0]+game_state[1]+game_state[2]:
            if square==' ':
                pass
            else:            
                full_squares+=1
        if full_squares==9 and game_on==True:
            game_on=False
            print '*************************'
            print 'game over! it\'s a draw...'
            print '*************************'
           
        if game_on==False:
            yn=raw_input('do you want to play another game [type Y for yes or anything else to quit]?\n').lower()
            if yn=='y':
                game_state=[list(row) for row in start_state]
                game_on=True
            else:
                sys.exit()

if __name__=='__main__':
    main()