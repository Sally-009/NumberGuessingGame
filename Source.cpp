#include<string>
#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

class game {
public:
    /* ------
        Game
       ------ */
    void start() {

        do
        {
			// Show title and rule
			title();
			section();

			// Get a random number
			getNum();

			// Get answer until the trigger become true
			for (int i = 1; !trigger; i++)
			{
				cout << "Trial #" << i << endl;
				cout << endl;
				getAnswer();

				section();

				// Check the answer
				if (answer == number)
				{
					cout << "Congrats! You got the right answer!" << endl;
					cout << "* GAME CLEAR *" << endl;

					trigger = true;
				}
				else
				{
					cout << "Oops! That is not the correct answer." << endl;

					// Subtract life point
					life--;

					// Check life point
					gameOver();

					// Give a hint if still alive
					if (!trigger)
						hint(i);
				}

				section();

			}

				// Play again or Exit
				cout << "Continue the game? Enter any number to continue or enter 999 to exit." << endl;
				cout << ">> ";
				cin >> end;

        } while (end != 999);
    }

    /* ----------
        Sections
       ---------- */
    void title() {

        // Reset
        system("cls");

        trigger = false;

        number = NULL;
        answer = NULL;
        life = MAX_LIFE;

        // Show title
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << "     Number Guessing Game    " << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << endl;
        cout << "Range: 1~10" << endl;
        cout << "Your life: " << MAX_LIFE << endl;
    }

    void getAnswer() {
        do
        {
            showLife();

            cout << "Your Answer >> ";
            cin >> answer;

            error = errorCheck();

        } while (error);
    }

    void hint(int i) {
        cout << "Hint: ";

        switch (i)
        {
        case 1: // larger or smaller than 5
            compareToFive();
            break;

        case 2: // even or odd
            evenOrOdd();
            break;

        default:
            cout << "* Unexpected Error *" << endl;
            exit(1);
            break;
        }
    }

    void section() {

        cout << endl;
        cout << "--------------------------------------------" << endl;
        cout << endl;

    }

    /* -----------
        Operation
       ----------- */

    void getNum() {

        srand((int)time(NULL));
        number = rand() % 10 + 1;
    }

    void showLife() {

        cout << "Your Life: ";
        for (int i = 0; i < life; i++)
        {
            cout << "* ";
        }
        cout << endl;

    }

    bool errorCheck() {

        if (answer < 1 || answer > 10)
        {
            cout << "*OUT OF RANGE*" << endl;

            return true;
        }
        else
            return false;

    }

    void gameOver() {

        if (life == 0)
        {
            cout << "*Game Over*" << endl;
            cout << "The correct answer was " << number << "!" << endl;

            trigger = true;
        }

    }

    void compareToFive() {

        if (number >= 5)
            cout << "This number is greater than or equal to 5." << endl;
        else
            cout << "This number is smaller than 5." << endl;

    }

    void evenOrOdd() {

        int remainder;
        
        // Calculate the remainder
        remainder = number % 2;

        if (remainder == 0)
            cout << "This number is even." << endl;
        else
            cout << "This number is odd." << endl;

    }

private:

    // const
    const int MAX_LIFE = 3;

    // numbers
    int number;
    int answer;

    // status
    int life = MAX_LIFE;

    bool error = false;     // input error
    bool trigger = false;   // end game flag

    // End flag
    int end;

};

// Main
int main() {

    game numGame;

    numGame.start();
}

