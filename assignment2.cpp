
/******************************************************************* ** 
** Program: assignment2.cpp
** Author: Kaushik Dontula
** Date: 10/07/2022
** Description: This program simulates a pokedex. A pokedex asks the user to search for particular pokemon through different search options and then outputs the information about that pokemon.
** Input: integers, strings. 
** Output: file or terminal with details of the pokemon selected.   
*******************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <fstream>

using namespace std;

struct Pokemon  {
     int dex_num;
     string name;
     string type;
     int num_moves;
     string* moves;
};

struct Pokedex {
     string trainer;
     int num_pokemon;
     Pokemon* dex;
};


void get_file_name(string &filename){
     cout << "Hello! Welcome to the pokedex." << endl;
     cout << "Please enter the filename that you would like to search through: "; 
     getline(cin, filename);
};

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

void open_file(ifstream &input, string filename){
     
     
     string extension = ".txt";
     extension.c_str();
     string file = filename + extension;
     input.open(file.c_str());

};

Pokemon* create_pokemons(int size){
     int dexnum;
     Pokemon* p_ptr = new Pokemon[size];
     return p_ptr;
};



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

     // cout << "Dex number = " << p.dex_num << endl;
     // cout << "Name of pokemon = " << p.name << endl;
     // cout << "Type = " << p.type << endl;
     // cout << "number of moves = " << p.num_moves << endl;
     // for (int i =0; i < p.num_moves; i++){
     //      cout << p.moves[i] << " ";
     // }


};

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


string* create_moves(int size){
     string* s_ptr = new string [size];
     return s_ptr;
};



void delete_info(Pokedex &poke){

     for(int i=0; i<poke.num_pokemon;i++){
          delete [] poke.dex[i].moves;
          poke.dex[i].moves = NULL;
     }


     delete [] poke.dex;
     poke.dex = NULL;


};

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

void get_search_option(int &searchoption){
     cout << endl << endl << "How would you like to search through the pokemon: " << endl << " 1 - search by dex number" << endl << " 2 - search by name" << endl << " 3 - search by dex type" << endl << " 4 - add your own Pokemon" << endl << " 5 - quit" << endl << "Option: ";
     cin >> searchoption;
};

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
     cout << temp[i].dex_num << endl;

     cout << endl << "What is the name of the pokemon (please capitalize the first letter): ";
     cin >> pokename;
     temp[i].name = pokename;
     cout << temp[i].name << endl;

     cout << endl << "What is the type of the pokemon (please capiralize the first letter): ";
     cin >> poketype;
     temp[i].type = poketype;
     cout << temp[i].type << endl;

     cout << endl << "How many moves does your pokemon have: ";
     cin >> pokenummoves;
     temp[i].num_moves = pokenummoves;
     cout << temp[i].num_moves << endl;

     temp[i].moves = create_moves(pokenummoves);

     for(int k = 0; k<pokenummoves; k++){
          string move;
          cout << "Enter move: ";
          cin >> move;
          temp[i].moves[k] = move;
     }
};

int main(){


     string filename;
     ifstream input;
     Pokedex poke;
     int output_type;
     int another;
     int searchoption;
     ofstream output;

     get_file_name(filename);
     open_file(input, filename);
     if (!input.is_open()){
          cout << "Error opening the file, please try again " << endl;
          return 0;
     }
     populate_pokedex_data(poke, input);
     create_file(output_type, output);
     
     do{
          get_search_option(searchoption);
          switch(searchoption){
               case 1:{
                    //search by dex number
                    search_number(poke, output, output_type);
                    break;
               };
               case 2:{
                    //search by name
                    search_name( poke, output, output_type);
                    break;
               };
               case 3:{
                    //search by type
                    search_type(poke, output, output_type);
                    break;
               }
               case 4:{
                    //add your own pokemon
                    int amnt_poke;
                    amnt_poke = poke.num_pokemon + 1;

                    Pokemon* temp = create_pokemons(amnt_poke);
                    cout << poke.num_pokemon + 1 << endl;
                    
                    add_new(temp, &poke);

                    delete [] poke.dex;
                    poke.dex = temp;
                    poke.num_pokemon++;

                    
               };

               case 5:{
                    
                    break;
               };

          }
     }while(searchoption != 5);
     delete_info( poke);
     

     return 0;
}