#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <fstream>
#include "Pokemon.h"

using namespace std;

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
                    //cout << poke.num_pokemon + 1 << endl;
                    
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