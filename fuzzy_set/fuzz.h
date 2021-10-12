#include <string>
#include <fstream>

struct Node {
    int data;
    double mu;
    Node *next;
};

typedef Node* TList;

void init(TList&);
void print(TList);
void clear(TList&);

bool isEmpty(TList);
bool inSet(TList, int);

void addToHead(TList&, int, double);
void addAfterNode(TList, int, double);
void addToSet(TList&, int, double);
void deleteFromHead(TList&);
void deleteAfterNode(TList);
void createByOrder(TList&, std::string);

TList findPlace(TList, int);
TList findCorrectPlace(TList, int);
TList unification(TList, TList);
TList intersection(TList, TList);