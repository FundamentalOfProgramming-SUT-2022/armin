#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main(){
	keypad(stdscr,TRUE);
	initscr();
	noecho();
	start_color();
	char mode_i = '-' ;
	char mode[100] = "NORMAL";
	char* command = (char*)malloc(200*sizeof(char));
	char c = 'o';
	int i = 0 ;
	int modei = 0 ;
	init_pair(1,COLOR_WHITE,COLOR_BLACK);
	init_pair(2,COLOR_RED,COLOR_BLACK);
	init_pair(3,COLOR_BLUE,COLOR_BLACK);
	init_pair(4,COLOR_GREEN,COLOR_BLACK);
		attron(COLOR_PAIR(1));
		for(int j = 0 ; j < LINES - 2 ; j ++){
			mvprintw(j,0,"~");
		}
attroff(COLOR_PAIR(1));
attron(COLOR_PAIR(2));
mvprintw(LINES-2,0,"%s","NORMAL");
mvprintw(LINES-2,7,"%c",mode_i);
mvprintw(LINES-1,0," ");
attroff(COLOR_PAIR(2));
while(1){
char c = getch();
if(c == 27){
	c = getch();
if(c == ':'){
	while(c != '\n'){
	command[i] = c ;
	command[i+1] = '\0';
	mvprintw(LINES-1,0,"%s",command);
	c = getch();
	i ++ ;
	}
	for(int j = 0 ; j < COLS ; j ++){
                mvprintw(LINES-1,j," ");
        }
	//
	char* p = strstr(command,"open");
	p += 5 ;
	FILE* my_file = fopen(p,"r");
	if(my_file == NULL){
		mvprintw(20,20,"nist hamchin faili");
	}
	char string_to_read[100] ;
	int z = 0 ;
	while(1){
		if(fgets(string_to_read,100,my_file) == NULL){
			break ;
		}
		mvprintw(z,0,"%s",string_to_read);
		z ++ ;
	}
	//
	command[0] = '\0';
	i = 0 ;
	}else if( c == 'v'){
		refresh();
		attron(COLOR_PAIR(2));
		mvprintw(LINES-2,0,"%s","VISUAL");
		mvprintw(LINES-1,0," ");
		attroff(COLOR_PAIR(2));
		int x = 0 ; int  y = 0 ;
		move(x,y);
		while(1){
                        char c = getch();
                        if(c == 'w'){
                                move(--x,y) ;
                        }else if(c == 'a'){
                                move(x,--y);
                        }else if(c == 'd'){
                                move(x,++y);
                        }else if(c == 's'){
                                move(++x,y);
                        }else if(c == 27){
                                break ;
                        }
		}	

	}else if( c == 'n'){
                refresh();
		attron(COLOR_PAIR(2));
                mvprintw(LINES-2,0,"%s","NORMAL");
                mvprintw(LINES-1,0," ");
		attroff(COLOR_PAIR(2));
        }else if( c == 'i'){
                refresh();
		attron(COLOR_PAIR(2));
                mvprintw(LINES-2,0,"%s","INSERT");
                mvprintw(LINES-1,0," ");
		attroff(COLOR_PAIR(2));
		int x = 0, y = 0 ;
		move(x,y);
		while(1){
			char c = getch();
			if(c == 'w'){
				move(--x,y) ;
			}else if(c == 'a'){
				move(x,--y);
			}else if(c == 'd'){
				move(x,++y);
			}else if(c == 's'){
				move(++x,y);
			}else if(c == 27){
				break ;
			}else{
				if(c == '\n'){
					y = 0 ;
					move(++x,y);
				
				}else{
					mvprintw(x,y,"%c",c);
					move(x,++y);
				}
			}
		}

        }else if(c == 's'){
		refresh();
		attron(COLOR_PAIR(2));
		mvprintw(LINES-2,7,"+");
		attroff(COLOR_PAIR(2));
		mvprintw(LINES-1,0," ");

	}


	}
}
getch();
	
	
	
endwin();
}	
