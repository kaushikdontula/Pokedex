#include "Pokemon.h"

using namespace std;




/******************************************************************* 
** Function: get_file_name
** Description: This function gets the name of the file that the user is tryign to extract data from
** Parameters: string name 
** Pre-conditions: the string name is created in int main and then called here to input the name that the user provides.
** Post-conditions: passes back the filename by reference as a string
*******************************************************************/
void get_file_name(string &filename){
     cout << "Hello! Welcome to the pokedex." << endl;
     cout << "Please enter the filename that you would like to search through: "; 
     getline(cin, filename);
};







/******************************************************************* 
** Function: create_file
** Description: This function asks the user if they would like to output to the terminal or to the file
** Parameters: int and ofstream 
** Pre-conditions: int and ofstream are created where the function is called: int main()
** Post-conditions: both are passed by reference so the output_type is recorded for the int main to store and the ofstream can output whatever the future functions need
*******************************************************************/
void create_file(int &output_type, ofstream &output){
     cout <<  endl << endl << "How would you like the pokemon information to be outputted (0 - terminal 1- file): ";
     cin >> output_type;

     
     if (output_type == 1){
          string outputname;
          cout << "What would you like the output file to be called: ";
          cin >> outputname;

          string extensiono = ".txt";
          extensiono.c_str();
          string outputfile = outputname + extensiono;
          output.open(outputfile.c_str(), ios::app); 
               if (!output.is_open()){
                    cout << "Error opening the file" << endl;
               }
     }
};






/******************************************************************* 
** Function: open_file
** Description: This function gets takes the input from the user and then creates the file by using a c string function
** Parameters: string name 
** Pre-conditions: the string name is created in int main and then called here to input the name that the user provides.
** Post-conditions: passes back the filename by reference as a string
*******************************************************************/
void open_file(ifstream &input, string filename){
     
     
     string extension = ".txt";
     extension.c_str();
     string file = filename + extension;
     input.open(file.c_str());

};






/******************************************************************* 
** Function: create_pokemons
** Description: This function gets creates a new pokemon data type when the user is trying to create their own pokemon. It uses the Pokemon struct. 
** Parameters: int size 
** Pre-conditions: the size is passed into the function to decide the size of the new dynamic array
** Post-conditions: passes back a pointer to the new dynamic array that was created
*******************************************************************/
Pokemon* create_pokemons(int size){
     int dexnum;
     Pokemon* p_ptr = new Pokemon[size];
     return p_ptr;
};







/******************************************************************* 
** Function: populate_pokemon
** Description: This function gets the Pokemon data type that is passed in and sets each value in the struct equal to the one from the file input
** Parameters: Pokemon, and ifstream 
** Pre-conditions: Pokemon, ifstream
** Post-conditions: passes back the Pokemon struct with its contents filled and passes back the ifstream by reference
*******************************************************************/
void populate_pokemon(Pokemon &p, ifstream &input){
     input >> p.dex_num;
     input >> p.name;
     input >> p.type;
     input >> p.num_moves;

     string *moves = new string[p.num_moves];
     p.moves = moves;

     for (int i =0; i < p.num_moves; i++){
          input >> p.moves[i];
     }
};






/******************************************************************* 
** Function: populate_pokedex_data
** Description: This function populates the pokedex struct with the pokemon struct and it creates a dynamic array of the pokemon structs
** Parameters: Pokedex, and ifstream 
** Pre-conditions: the string name is created in int main and then called here to input the name that the user provides.
** Post-conditions: passes back the filename by reference as a string
*******************************************************************/
void populate_pokedex_data(Pokedex &p , ifstream &input){
     int poke_num;

     input >> poke_num;
     cout << "Pokemon number = " << poke_num << endl;

     Pokemon* dex = new Pokemon[poke_num];
     p.dex = dex;

     p.num_pokemon = poke_num;

     for (int i=0; i<poke_num; i++){
          populate_pokemon(p.dex[i], input);
     }
};





/******************************************************************* 
** Function: create_moves
** Description: This function creates a dynamic array for the moves that a pokemon has and then passes the pointer to that array back
** Parameters: a size variable 
** Pre-conditions: int size
** Post-conditions: passes back pointer to the dynamic array
*******************************************************************/
string* create_moves(int size){
     string* s_ptr = new string [size];
     return s_ptr;
};






/******************************************************************* 
** Function: delete_into
** Description: This function deletes all the dynamic memory that we have created
** Parameters: Pokedex poke 
** Pre-conditions: Pokedex struct data type
** Post-conditions: passes back the Pokedex struct data type with everything deleted and equal to NULL
*******************************************************************/
void delete_info(Pokedex &poke){


     for(int i=0; i<poke.num_pokemon;i++){
          delete [] poke.dex[i].moves;
          poke.dex[i].moves = NULL;
     }

     delete [] poke.dex;
     poke.dex = NULL;


};





/******************************************************************* 
** Function: output_on_terminal
** Description: This function will output the users searches on the terminal rather than a file
** Parameters: int i, Pokedex poke 
** Pre-conditions: integer and Pokedex
** Post-conditions: prints the values the user is searching for on the terminal
*******************************************************************/
void output_on_terminal(int i, Pokedex poke){
     //cout << endl << "This works" << endl;
     cout << endl << "The pokemon details you searched for: " << endl;
     cout << "Dex #: " << poke.dex[i].dex_num << endl;
     cout << "Name : " << poke.dex[i].name << endl;
     cout << "Type : " << poke.dex[i].type  << endl;
     cout << "Number of moves : " << poke.dex[i].num_moves << endl << endl;

     cout << endl << "Moves: " << endl;
     for (int j = 0; j < poke.dex[i].num_moves; j++){
               cout << poke.dex[i].moves[j] << " " << endl;
     }
}





/******************************************************************* 
** Function: output_on_file
** Description: This function will output the users searches on the file rather than  terminal
** Parameters: int i, ofstream, Pokedex poke 
** Pre-conditions: integer ,ofstream and Pokedex struct
** Post-conditions: prints the values the user is searching for on the file of their choosing
*******************************************************************/
void output_on_file(int i, ofstream &output,Pokedex poke ){
     //cout << endl << "This works" << endl;
     output << endl << "The pokemon details you searched for: " << endl;
     output << "Dex #: " << poke.dex[i].dex_num << endl;
     output << "Name : " << poke.dex[i].name << endl;
     output << "Type : " << poke.dex[i].type  << endl;
     output << "Number of moves : " << poke.dex[i].num_moves << endl << endl;

     output << endl << "Moves: " << endl;
     for (int j = 0; j < poke.dex[i].num_moves; j++){
               output << poke.dex[i].moves[j] << " " << endl;
     }
};






/******************************************************************* 
** Function: get_search_option
** Description: gets the search option that the user picks and passes it back to int main
** Parameters: int search option 
** Pre-conditions: integer 
** Post-conditions: passes back the search option that the user entered
*******************************************************************/
void get_search_option(int &searchoption){
     cout << endl << endl << "How would you like to search through the pokemon: " << endl << " 1 - search by dex number" << endl << " 2 - search by name" << endl << " 3 - search by dex type" << endl << " 4 - add your own Pokemon" << endl << " 5 - quit" << endl << "Option: ";
     cin >> searchoption;
};







/******************************************************************* 
** Function: search_number
** Description: This function will search for the dex number of the pokemon
** Parameters: Pokedex poke , ofstream output, output_type
** Pre-conditions: Pokedex poke , ofstream output, output_type
** Post-conditions: takes the struct and outputs it either on the terminal or on the file if the search was found
*******************************************************************/
void search_number(Pokedex poke, ofstream &output, int output_type){
     int dex_number;
     cout << "Please enter the dex number you are searching for: ";
     cin >> dex_number;
     int not_there = 0;

     for (int i=0; i < poke.num_pokemon; i++){
          if (dex_number == poke.dex[i].dex_num){
               if (output_type == 1){
                    output_on_file( i, output, poke);
               }
               if (output_type == 0){
                    output_on_terminal(i, poke);
               }
               
          }
          if (!(dex_number == poke.dex[i].dex_num)){
               //cout << endl << "This does not work" << endl;
               not_there++;
          }
     }

     if (not_there == poke.num_pokemon){
          cout << "The pokemon is not there. Please try another search option. " << endl << endl;
     }


};







/******************************************************************* 
** Function: search_name
** Description: This function will search for the name of the pokemon
** Parameters: Pokedex poke , ofstream output, output_type
** Pre-conditions: Pokedex poke , ofstream output, output_type
** Post-conditions: takes the struct and outputs it either on the terminal or on the file if the search was found
*******************************************************************/
void search_name(Pokedex poke, ofstream &output, int output_type){
     string name = "";
     cout << "Please enter the name of the pokemon you are searching for (capitalize first letter): ";
     cin >> name;
     int not_there;
     
     for (int i=0; i < poke.num_pokemon; i++){
          if (name == poke.dex[i].name){
               if (output_type == 1){
                    output_on_file( i, output, poke);
               }
               if (output_type == 0){
                    output_on_terminal(i, poke);
               }
          }
          if (!(name == poke.dex[i].name)){
               //cout << endl << "This does not work" << endl;
               not_there++;
          }
     }
     if (not_there == poke.num_pokemon){
     cout << "The pokemon is not there. Please try another search option. " << endl << endl;
     }
};






/******************************************************************* 
** Function: search_type
** Description: This function will search for the type of the pokemon
** Parameters: Pokedex poke , ofstream output, output_type
** Pre-conditions: Pokedex poke , ofstream output, output_type
** Post-conditions: takes the struct and outputs it either on the terminal or on the file if the search was found
*******************************************************************/
void search_type(Pokedex poke, ofstream &output, int output_type){
     string type = "";
     cout << "Please enter the type of the pokemon you are searching for (capitalize first letter): ";
     cin >> type;
     int not_there;

     for (int i=0; i < poke.num_pokemon; i++){
          if (type == poke.dex[i].type){
               if (output_type == 1){
                    output_on_file( i, output, poke);
               }
               if (output_type == 0){
                    output_on_terminal(i, poke);
               }
          }
          if (!(type == poke.dex[i].type)){
               //cout << endl << "This does not work" << endl;
               not_there++;
          }
     }
     if(not_there == poke.num_pokemon){
          cout << "The pokemon is not there. Please try another search option. " << endl << endl;
     }
}





/******************************************************************* 
** Function: add_new
** Description: This function will add a new pokemon to the struct using a new dynamic array
** Parameters: Pokemon and Pokedex
** Pre-conditions: Pokemon temp[], and Pokedex poke[]
** Post-conditions: adds a new element into the struct array
*******************************************************************/
void add_new(Pokemon temp[], Pokedex poke[]){
     int i =0;
     int pokenum;
     string pokename;
     string poketype;
     int pokenummoves;


     for(i ;i<poke->num_pokemon; i++){
          temp[i] = poke->dex[i];
     }

     cout << endl << "What is the Dex# of the pokemon: ";
     cin >> pokenum;
     temp[i].dex_num = pokenum;
     //cout << temp[i].dex_num << endl;

     cout << endl << "What is the name of the pokemon (please capitalize the first letter): ";
     cin >> pokename;
     temp[i].name = pokename;
     //cout << temp[i].name << endl;

     cout << endl << "What is the type of the pokemon (please capiralize the first letter): ";
     cin >> poketype;
     temp[i].type = poketype;
     //cout << temp[i].type << endl;

     cout << endl << "How many moves does your pokemon have: ";
     cin >> pokenummoves;
     temp[i].num_moves = pokenummoves;
     //cout << temp[i].num_moves << endl;

     temp[i].moves = create_moves(pokenummoves);

     for(int k = 0; k<pokenummoves; k++){
          string move;
          cout << "Enter move: ";
          cin >> move;
          temp[i].moves[k] = move;
     }
};