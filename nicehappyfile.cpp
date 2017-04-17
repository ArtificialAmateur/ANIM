/*
 * Automatic Network Intrusion Monitor 
 * @ArtificialAmateur && @alefir
 */

// -|----------- Launcher -----------|- //

#include <iostream>

class Anim{

public:
	const char* version = "Anim v0.0.1";
	static int launcher(){
		const char* jackal =
		"    ___   ________   ________   ___  __     ________   ___          \n"
		"   |\\  \\ |\\   __  \\ |\\   ____\\ |\\  \\|\\  \\  |\\   __  \\ |\\  \\         \n"
		"   \\ \\  \\\\ \\  \\|\\  \\\\ \\  \\___| \\ \\  \\/  /|_\\ \\  \\|\\  \\\\ \\  \\        \n"
		" __ \\ \\  \\\\ \\   __  \\\\ \\  \\     \\ \\   ___  \\\\ \\   __  \\\\ \\  \\       \n"
		"|\\  \\\\_\\  \\\\ \\  \\ \\  \\\\ \\  \\____ \\ \\  \\\\ \\  \\\\ \\  \\ \\  \\\\ \\  \\____  \n"
		"\\ \\________\\\\ \\__\\ \\__\\\\ \\_______\\\\ \\__\\\\ \\__\\\\ \\__\\ \\__\\\\ \\_______\\\n"
		" \\|________| \\|__|\\|__| \\|_______| \\|__| \\|__| \\|__|\\|__| \\|_______|\n"
		"                                                                    \n"
		"          .                                                      .\n"
		"        .n                   .                 .                  n.\n"
		"  .   .dP                  dP                   9b                 9b.    .\n"
		" 4    qXb         .   dX                     Xb   .        dXp     t\n"
		"dX.    9Xb  .dXb    __                         __    dXb.     dXP     .Xb\n"
		"9XXb._       _.dXXXXb dXXXXbo.                 .odXXXXb dXXXXb._       _.dXXP\n"
		" 9XXXXXXXXXXXXXXXXXXXVXXXXXXXXOo.           .oOXXXXXXXXVXXXXXXXXXXXXXXXXXXXP\n"
		"  `9XXXXXXXXXXXXXXXXXXXXX'~   ~`OOO8b   d8OOO'~   ~`XXXXXXXXXXXXXXXXXXXXXP'\n"
		"    `9XXXXXXXXXXXP' `9XX'   DIE    `98v8P'  HUMAN   `XXP' `9XXXXXXXXXXXP'\n"
		"        ~~~~~~~       9X.          .db|db.          .XP       ~~~~~~~\n"
		"                        )b.  .dbo.dP'`v'`9b.odb.  .dX(\n"
		"                      ,dXXXXXXXXXXXb     dXXXXXXXXXXXb.\n"
		"                     dXXXXXXXXXXXP'   .   `9XXXXXXXXXXXb\n"
		"                    dXXXXXXXXXXXXb   d|b   dXXXXXXXXXXXXb\n"
		"                    9XXb'   `XXXXXb.dX|Xb.dXXXXX'   `dXXP\n"
		"                     `'      9XXXXXX(   )XXXXXXP      `'\n"
		"                              XXXX X.`v'.X XXXX\n"
		"                              XP^X'`b   d'`X^XX\n"
		"                              X. 9  `   '  P )X\n"
		"                              `b  `       '  d'\n"
		"                               `             '";
		std::cout<<jackal;
		return 0;
	}

	static int help(){
		const char* help = 
		"Usage: anim [OPTION]\n"
		"Automatic Network Intrusion Monitor\n"
		"\n"
		"\t-m, --module [MODULE] \tRuns the module of name or number specified\n"
		"\t-l, --list\t\tList installed modules\n"
		"\t-v, --version\t\tDisplay currently installed version\n"
		"\t-h, --help\t\tDisplay this help text";
		std::cout<<help;
		return 0;
	}
};

int main(int argc, char* argv[]){
	if(argc<2){
		Anim::help();
		return 1;
	}
	switch(argv[1]){
		case "-m"||"--module": if(argc<3){ std::cout<<"Usage: anim -m [MODULE]"; return 1;}
			else Anim::run_module(argv[2]); break;
		case "-l"||"--list": Anim::list_modules(); return 0;
		case "-v"||"--version": std::cout<<version; return 0;
		case "-h"||"--help": Anim::help(); return 0;
		default: Anim::help(); return 1;
	}
}
