#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>


using namespace std;

int main()
{
    ifstream flux("texte.txt");
    string nodeActual , first , last ;
    int N ;
    queue<string> node;
    multimap<string,string> elements;
    set<string> nodeParcouru;
    std::set<string>::iterator it;

    //Lecture du nombre d'arrête
    flux >> N;

    for(int i=0;i<N;++i){
        string a, b;
        flux >>a;
        flux >>b;
        elements.insert( std::pair<string,string>(a,b) );
    }

    cout << " Enter the fisrt element : ";
    cin >> first;
    cout << "Enter the last element : ";
    cin >> last;

    nodeActual = first;
    node.push(first);
    do{

        std::pair< multimap<string,string>::iterator , multimap<string,string>::iterator > follow;
        follow = elements.equal_range(nodeActual);
        for( multimap<string, string>::iterator l = follow.first; l!=follow.second; ++l ){
            //Vérifier que l'élément n'appartient pas à la liste des éléments déjà parcouru
            it = nodeParcouru.find(l->second);
            if( *it!=l->second ){
                //Ajouter les suivants
                node.push(l->second);
            }
        }

        //Ajouter l'élement actuel à la liste des éléments parcouru
        nodeParcouru.insert(nodeActual);
        //Enlevé l'élément actuel de la file
        node.pop();
        //Changer l'élément actuel
        nodeActual = node.front();
    }while( !nodeParcouru.empty() && nodeActual!=last );


    if( !nodeParcouru.empty() ){
        nodeParcouru.insert(last);
    }

    //Afficher la liste des éléments parcouru
    for(it = nodeParcouru.begin(); it!=nodeParcouru.end(); ++it ){
        cout << *it << " ";
    }

    return 0;
}
