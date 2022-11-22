#ifndef Pokemon_h
#define Pokemon_h
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


void get_file_name(string &filename);
void create_file(int &output_type, ofstream &output);
void open_file(ifstream &input, string filename);
Pokemon* create_pokemons(int size);
void populate_pokemon(Pokemon &p, ifstream &input);
void populate_pokedex_data(Pokedex &p , ifstream &input);
string* create_moves(int size);
void delete_info(Pokedex &poke);
void output_on_terminal(int i, Pokedex poke);
void output_on_file(int i, ofstream &output,Pokedex poke );
void get_search_option(int &searchoption);
void search_number(Pokedex poke, ofstream &output, int output_type);
void search_name(Pokedex poke, ofstream &output, int output_type);
void search_type(Pokedex poke, ofstream &output, int output_type);
void add_new(Pokemon temp[], Pokedex poke[]);




#endif