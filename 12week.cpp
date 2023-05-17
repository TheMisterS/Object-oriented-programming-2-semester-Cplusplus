#include <iostream>
#include <sstream>
#define MAX_COMMANDS 10 //set how many commands may the player use.
#define WORD "hello" // set the desired word
using namespace std;
// CLASSES
class GuessWord;
class Action {
    static int times_called;
 public:
    virtual void run(GuessWord* guess_word) = 0;
    Action();
    int get_times_called();
};
int Action::times_called = 0;
class GuessWord {
    std::string word;
    std::string hidden_word;
 public:
    GuessWord(const std::string& word);
    void guess_char(char chr);
    bool have_won();
    void reveal_letter(int index);
    void set_word(const std::string& word);
    void show_hidden_word();
    int get_word_length();
};
class GuessLetter : public Action{
    char guess;
 public:
    void run(GuessWord* guess_word);
    GuessLetter(char DesiredChar);
};
class RevealLetter : public Action{
    int index;
 public:
    void run(GuessWord* guess_word);
    RevealLetter(int DesiredIndex);
};
class RevealRandom : public Action{
 public:
    void run(GuessWord* guess_word);
};
// CLASS FUNCTIONS
GuessWord::GuessWord(const std::string& word) {
    set_word(word);
}
void GuessWord::guess_char(char chr) {
    for (int i = 0; i < word.size(); i++) {
        if (word[i] == chr && hidden_word[i] == '*') {
            reveal_letter(i);
        }
    }
}
bool GuessWord::have_won(){
    return word == hidden_word;
}
void GuessWord::reveal_letter(int index) {
    if (index >= 0 && index < word.size()) {
        hidden_word[index] = word[index];
    }
}
void GuessWord::set_word(const string& word) {
    this->word = word;
    this->hidden_word.clear();
    for (int i = 0; i < word.size(); i++)
        hidden_word.push_back('*');
}
void GuessWord::show_hidden_word() {
    cout << "WORD: " << hidden_word << endl;
}
// FUNCTIONS I ADDED
Action::Action(){
    times_called++;
}
int Action::get_times_called(){
    return times_called;
}
int GuessWord::get_word_length(){
    return word.length();
}
void GuessLetter::run(GuessWord* guess_word){
    guess_word->guess_char(guess);
};
GuessLetter::GuessLetter(char DesiredChar){
    guess = DesiredChar;
}
void RevealLetter::run(GuessWord* guess_word){
    guess_word->reveal_letter(index);
};
RevealLetter::RevealLetter(int DesiredIndex){
    index = DesiredIndex - 1;
}
void RevealRandom::run(GuessWord* guess_word){
    int index = std::rand() % guess_word->get_word_length();
    guess_word->reveal_letter(index);
};
// MAIN GAME
int main(int argc, char** argv) {
    using namespace std;
    GuessWord gameWord(WORD); // The main object of the game, set the argument as the desired word to be guessed
    RevealRandom checkTimes; // object for checking amount of entered commands.
    string input, desiredAction; // Variables for collecting input
    int powerUpAmount = 0; // variable for checking the amount of used powerups.
    //The Game
    cout << "Welcome to the guess letter game" << endl;
    cout << "AVAILABLE ACTIONS: GuessLetter letter; RevealLetter position; RevealRandom" << endl;
    cout << "You may only use RevealLetter and RevealRandom twice(combined)." << endl;
    gameWord.show_hidden_word();
    while(!gameWord.have_won()){
        cout << ">> ";
        getline(cin, input);
        stringstream ss(input);
        ss >> desiredAction;
        if(desiredAction == "GuessLetter"){
            char letter;
            ss >> letter;
            GuessLetter MakeGuess(letter);
            MakeGuess.run(&gameWord);
            gameWord.show_hidden_word();
        }else if(desiredAction == "RevealLetter"){
            if(powerUpAmount >= 2){
                cout << "You have used all the power ups, pleas use the GuessLetter command now." << endl;
                continue;;
            }
            int index;
            ss >> index;
            RevealLetter RevealGuess(index);
            RevealGuess.run(&gameWord);
            gameWord.show_hidden_word();
            powerUpAmount++;
        }else if(desiredAction == "RevealRandom"){
            if(powerUpAmount >= 2){
                cout << "You have used all the power ups, pleas use the GuessLetter command now." << endl;
                continue;
            }
            RevealRandom RandomGuess;
            RandomGuess.run(&gameWord);
            gameWord.show_hidden_word();
            powerUpAmount++;
        }else{
            cout << "Incorrect command, try again!" << endl;
        }
        if(checkTimes.get_times_called() >= MAX_COMMANDS){ //checks the amount of times commands have been entered.
            cout << "You have surpassed the maximum amount of tries("<< MAX_COMMANDS <<"), you lose!" << endl;
            return 0;
        }
    }
    cout << "Congratulations you have won the game!" << endl;
}