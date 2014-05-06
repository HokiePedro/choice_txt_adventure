#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void StoL(char s[]) // I set this as a void function because it didn't want a return value
{

    for (*s; *s != NULL; *s++) //A for statement that looks through the array, starting at zero, until null
    {
		if (*s >= 65 && *s <= 90) //Checks to see if the char in the array is an ascii character a through z.
        {
            *s = (*s + 32); //once the uppercase letter is found, it will be changed to its corresponding

        } //lowercase asii character, which is 32 hex digits lower.
		else
		{
			*s = *s;
		}
	}
}

int main()
{
	string input = "";
	typedef enum stages {intro, gender, weaponsChoice, location };

	stages stage = intro;
	while(1){

	switch(stage)
	{
	case intro:
		{
			cout << "Welcome to Choice" << endl;
			cout << "Please press any key to continue" << endl;
			getline(cin, input);
			if(input != "")
			{
				cout << string(100, '\n');
				cout << "Any choice that you make beyond this point will have a drastic effect on your fate" << string(10, '\n') << endl;
				stage = gender;
				break;
			}
			
		}
		break;
	case gender:
		{
			cout << string(30, '\n') << "Now tell us, are you a boy or a girl? Don't lie to us." << endl;
			string gend;
			getline(cin, gend);
			//for (int i=0;i<input.length();i++){ 
			//	input[i]=tolower(input[i]);
            //cout << input << endl;
			//}
			
  
		//	for (int i=0; i<input.length(); ++i)
			;//	tolower(input[i]);


			if(gend == "boy")
			{
				cout << string(5, '\n') << "Ah, of course! You are a boy!"  <<  '\n' << endl;
				stage = weaponsChoice;
				break;
			}
			else if(gend == "girl" )
			{
				cout << string(5, '\n') << "Ah, of course! You are a girl!" << '\n' << endl;
				stage = weaponsChoice;
				break;
			}
			else{
				cout << string(50, '\n') << "LIES!!! You shall be put to death!" << string(10, '\n') << "GAME OVER" << endl;
				stage = intro;
				break;
			}
		}
		break;
	case weaponsChoice:
		{
			int i = 0;
			cout << "Alright now, considering your life expectancy, there is not time for formalities, " << '\n' << "you can just give me your name if you make it out alive" << endl;
			cout << string(5, '\n') << endl;
			

			cout << "How about you just tell me what kind of weapon you want to choose?" << endl;
			cout << "You can choose from: " << '\n' <<  "(1) the shotgun " <<'\n' <<  "(2) the dual pistols" <<'\n' <<  "(3) the assault rifle" <<'\n' <<  "(4) the cross bow" << endl;
			stage = intro;
			break;
		}
		break;
	}
}

	return 0;
}
