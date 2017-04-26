//============================================================================
// Name        : anim.cpp
// Author      : @ArtificialAmateur @alefir
// Version     : 0.0.1a
// Copyright   : dont steal our things
// Description : Automatic Network Intrusion Monitor
//============================================================================

#include <iostream>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string>
#include <unistd.h>

using namespace std;

const char* version = "Anim v0.0.1a";
int launcher() {
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
	cout << jackal;
	return 0;
}

int help() {
	const char* help =
			"Usage: anim [OPTION]\n"
					"Automatic Network Intrusion Monitor\n"
					"\n"
					"\t-m, --module [MODULE] \tRuns the module of name or number specified\n"
					"\t-l, --list\t\tList installed modules\n"
					"\t-v, --version\t\tDisplay currently installed version\n"
					"\t-h, --help\t\tDisplay this help text\n";
	cout << help;
	return 0;
}

int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

int list_modules() {
	string dir = string("./modules/");
    vector<string> files = vector<string>();

    getdir(dir,files);

    for (unsigned int i = 0;i < files.size();i++) {
        if ( files[i] != "." && files[i] != ".." ) {
			cout << files[i] << endl;
		}
    }
    return 0;
}

int run_module(string module) {
	cout << "Run module " << module << endl;
	string modpath = "./modules/" + module;
	cout << "path: " << modpath << endl;
	execlp( modpath.c_str() , "r" );
	return 0;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		help();
		return 4;
	}
	// C++ Doesn't allow strings in switches. I'm sorry.
	for ( int i = 1; i < argc; i++ ){
		string optchar = argv[i];
		if ( optchar == "-v" || optchar == "--version" ) {
			cout << version << endl;
			return 0;
		}
		else if ( optchar == "-h" || optchar == "--help" ) {
			help();
			return 0;
		}
		else if ( optchar == "-l" || optchar == "--list" ) {
			list_modules();
			return 0;
		}
		else if ( optchar == "-m" || optchar == "--module" ) {
			if ( argc == 3 ) {
				run_module( string(argv[2]) );
				return 0;
			} else {
				help();
				return 3;
			}

		} else {
			help();
			return 1;
		}
	}
	return 2;
}
