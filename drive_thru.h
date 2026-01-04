#ifndef DRIVE_THRU_H
#define DRIVE_THRU_H

#include <iostream>
#include <fstream>

using namespace std;


struct TreeNode {
    char name[50];
    char customerCode[10];  // Diubah dari nik[20] ke customerCode[10]
    int amount;
    int height;
    int freq;
    char ch;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(const char* n, const char* code, int a);  // Parameter diganti
    TreeNode(char c, int f);
};

struct Item {
    char name[50];
    int price;
    char category[20];
    int quantity;
    Item* next;
    int id;
    int cost;
    
    Item();
    Item(const char* n, int p, const char* c, int q);
};

struct Transaction {
    int orderNumber;
    char customerName[50];
    char customerCode[10];  // Diubah dari customerNIK[20] ke customerCode[10]
    int totalAmount;
    int foodCount;
    int drinkCount;
    char date[20];
    Transaction* next;
    
    Transaction();
    Transaction(int num, const char* name, const char* code, int total, int food, 
               int drink, const char* dt);  // Parameter diganti
};

struct Customer {
    char name[50];
    char customerCode[10];  // Diubah dari nik[20] ke customerCode[10]
    int totalSpent;
    int visitCount;
    Customer* next;
    
    Customer();
    Customer(const char* n, const char* code, int t);  // Parameter diganti
};

struct QueueNode {
    Transaction* transaction;
    QueueNode* next;
    
    QueueNode(Transaction* t);
};


class ShoppingCart {
private:
    struct Node {
        Item* data;
        Node* next;
        Node();
        Node(Item* d);
    };
    
    Node* top;
    int itemCount;
    char customerName[50];
    char customerCode[10];  // Diubah dari customerNIK[20] ke customerCode[10]
    
public:
    ShoppingCart();
    ~ShoppingCart();
    void push(Item* item);
    Item* pop();
    bool isEmpty();
    void display();
    int getTotalPrice();
    int getFoodCount();
    int getDrinkCount();
    int getTotalItems();
    bool cancelLastItem();
    void setCustomerName(const char* name);
    void getCustomerName(char* name);
    void setCustomerCode(const char* code);  // Diubah dari setCustomerNIK
    void getCustomerCode(char* code);        // Diubah dari getCustomerNIK
    void clearCart();
};

class TransactionQueue {
private:
    QueueNode* front;
    QueueNode* rear;
    int size;
    
public:
    TransactionQueue();
    ~TransactionQueue();
    void enqueue(Transaction* transaction);
    Transaction* dequeue();
    bool isEmpty();
    int getSize();
    void displayQueue();
    Transaction* peek();
};

class CustomerBinaryTree {
private:
    TreeNode* root;
    
    void insertRecursive(TreeNode* &node, const char* name, const char* code, int amount);
    void displayInOrder(TreeNode* node);
    TreeNode* searchRecursive(TreeNode* node, const char* code);
    void destroyTree(TreeNode* node);
    
public:
    CustomerBinaryTree();
    ~CustomerBinaryTree();
    void insert(const char* name, const char* code, int amount);
    void display();
    TreeNode* search(const char* code);
    int getHeight(TreeNode* node);
};

class CustomerAVLTree {
private:
    TreeNode* root;
    
    int getHeight(TreeNode* node);
    int getBalance(TreeNode* node);
    TreeNode* rightRotate(TreeNode* y);
    TreeNode* leftRotate(TreeNode* x);
    TreeNode* insertRecursive(TreeNode* node, const char* name, const char* code, int amount);
    void displayInOrder(TreeNode* node);
    TreeNode* searchRecursive(TreeNode* node, const char* code);
    void destroyTree(TreeNode* node);
    
public:
    CustomerAVLTree();
    ~CustomerAVLTree();
    void insert(const char* name, const char* code, int amount);
    void display();
    TreeNode* search(const char* code);
};

class HuffmanCoding {
private:
    struct MinHeapNode {
        TreeNode* node;
        MinHeapNode* next;
        MinHeapNode(TreeNode* n);
    };
    
    TreeNode* root;
    MinHeapNode* minHeapHead;
    
    void insertToMinHeap(TreeNode* node);
    TreeNode* extractMin();
    void generateCodes(TreeNode* node, char* code, int depth, char huffmanCodes[][100]);
    void destroyHuffmanTree(TreeNode* node);
    
public:
    HuffmanCoding();
    ~HuffmanCoding();
    void buildTree(char data[], int freq[], int size);
    void printCodes();
    void encode(const char* text, char* encoded);
    void decode(const char* encodedText, char* decoded);
};

class TransactionHistory {
private:
    Transaction* head;
    int count;
    int totalRevenue;
    int totalProfit;
    int totalFoodSold;
    int totalDrinkSold;
    
    TransactionQueue pendingQueue;
    CustomerBinaryTree customerTree;
    CustomerAVLTree customerAVL;
    HuffmanCoding huffman;
    
    void addToCustomerTree(const char* name, const char* code, int amount);
    void addToCustomerAVL(const char* name, const char* code, int amount);
    
public:
    TransactionHistory();
    ~TransactionHistory();
    void addTransaction(int orderNum, const char* customerName, const char* code, int total, 
                       int food, int drink, const char* date);
    void displayAllTransactions();
    void displayStatistics();
    void displayDailyReport();
    void saveTransactionsToFile();
    int getTotalTransactions();
    int getTotalRevenue();
    int getTotalProfit();
    Transaction* findTransaction(int orderNum);
    Transaction* searchTransactionByCustomer(const char* customerName);
    Transaction* searchTransactionByCode(const char* code);  // Diubah dari searchTransactionByNIK
    void searchTransactionByDate(const char* date);
    void searchTransactionByAmountRange(int minAmount, int maxAmount);
    int getFoodSold();
    int getDrinkSold();
    
    void addToPendingQueue(Transaction* transaction);
    void processPendingQueue();
    void displayPendingQueue();
    void displayCustomerTree();
    void displayCustomerAVL();
    void processHuffmanDemo();
    
    void searchTransactionMenu();
    void displayTransactionDetails(Transaction* trans);
};

class CustomerManager {
private:
    Customer* head;
    int count;
    
public:
    CustomerManager();
    ~CustomerManager();
    void addCustomer(const char* name, const char* code, int total);
    void displayAllCustomers();
    Customer* findCustomer(const char* name);
    Customer* findCustomerByCode(const char* code);  // Diubah dari findCustomerByNIK
    int getCustomerCount();
    void saveCustomersToFile();
    Customer* getTopSpender();
    void searchCustomerByName(const char* name);
    void searchCustomerByCode(const char* code);  // Diubah dari searchCustomerByNIK
};

class DriveThruSystem {
private:
    ShoppingCart cart;
    TransactionHistory transactions;
    CustomerManager customers;
    
    Item menuItems[10];
    int orderCounter;
    char adminPassword[20];
    
    void initializeMenu();
    Item* createItem(const char* name, int price, const char* category, int quantity);
    void displayMainMenu();
    void displayAdminMenu();
    void displayCustomerMenu();
    bool verifyAdmin();
    void printReceipt(int orderNum, const char* customerName, const char* code, int total, 
                     int food, int drink);
    void runAdminMode();
    void runCustomerMode();
    
public:
    DriveThruSystem();
    void run();
};


void copyString(char* dest, const char* src, int maxLen);
bool stringsEqual(const char* str1, const char* str2);
int stringLength(const char* str);
int max(int a, int b);
void clearScreen();
bool isValidCustomerCode(const char* code);  // Diubah dari isValidNIK

#endif
