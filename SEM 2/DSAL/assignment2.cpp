/* Problem Statement :
A Dictionary stores keywords and its meanings. Provide facility for adding new keywords, deleting
keywords, updating values of any entry. Provide facility to display whole data sorted in
Ascending / Descending order. Also find how many maximum comparisons may require for finding any keyword.
Use Binary Search Tree for implementation. */

#include<iostream>
using namespace std;

class Node{
    Node* left;
    Node* right;
    string keyword;
    string meaning;

    public:
        Node(){
            left = NULL;
            right = NULL;
            keyword = "";
            meaning = "";
        }

        friend class Dictionary;
};

class Dictionary{

    Node* root;

    public:

        // This is constructor of class Dictionary
        // Here root is set to NULL
        Dictionary(){
            root = NULL;
        }

        // This will return address of root node
        Node* get_root(){
            return root;
        }

        // Creating new node i.e keyword in Dictionary
        Node* create_keyword(string k){
            Node* new_node = new Node();
            new_node->keyword = k;
            cout<<"Enter Meaning : ";
            cin>>new_node->meaning;
            cout<<"Keyword \""<<new_node->keyword<<"\" with Meaning \""<<new_node->meaning<<"\" is add in Dictionary"<<endl;
            return new_node;
        }

        // This will add new keyword in dictionary
        void add_keyword(string k){
            if(root == NULL){
                root = create_keyword(k);
            }
            else{
                Node *current = root;
                while (1)
                {
                    // Keyword is not Present Dictionary and It will be Added in Dictionary
                    if(current->keyword != k){
                        // Adding new keyword to left child of current node
                        if(current->keyword > k){
                            if(current->left == NULL){
                                current->left = create_keyword(k);
                                return ;
                            }
                            current = current->left;
                        }
                        // Adding new keyword to right child of current node
                        else{
                            if(current->right == NULL){
                                current->right = create_keyword(k);
                                return ;
                            }
                            current = current->right;
                        }
                    }
                    // Keyword already Present in Dictionary
                    else{
                        cout<<"Keyword \""<<k<<"\" with meaning \""<<current->meaning<<"\" is Already Present in Dictionary. Enter Different Keyword."<<endl;
                        return ;
                    }
                }
            }
        }

        // This will update meaning of keyword
        void update_meaning(string k){
            Node* current = root;
            while (current != NULL)
            {
                // Keyword is Searched in Dictionary
                // And its meaning will be Updated
                if(current->keyword == k){
                    cout<<"Keyword \""<<k<<"\" with Meaning \""<<current->meaning<<"\" is Present in Dictionary."<<endl;

                    cout<<"Enter Updating Meaning of Keyword \""<<k<<" : ";
                    cin>>current->meaning;

                    cout<<"Meaning of Keyword \""<<k<<"\" is Updated Successfully."<<endl;
                    return ;
                }

                // Keyword is not yet Searched in Dictionary
                // This will traverse till current becomes equal to NULL
                else{
                    if(current->keyword > k){
                        current = current->left;
                    }
                    else{
                        current = current->right;
                    }
                }
            }

            // Required Keyword is not Present in Dictionary
            cout<<"Keyword : \""<<k<<"\" is Not Present in Dictionary."<<endl;
        }

        // This will delete keyword from dictionary
        void delete_keyword(string k){
            Node *current = root, *parent = root, *next = root;
            while (current != NULL)
            {
                if(current->keyword == k){

                    // This means deleting node is leaf node i.e don't have left and right node
                    // So, simply delete current
                    if(current->left == NULL && current->right == NULL){
                        if(parent->left == current){
                            parent->left = NULL;
                        }
                        else{
                            parent->right = NULL;
                        }
                        delete current;
                    }

                    // VIMP NOTE
                    // This means deleting node is non leaf node having both left and right node
                    // For this we are traversing in left sub tree of current node to replace current node with highest value of left sub tree of current
                    else if(current->left != NULL && current->right != NULL){
                        next = current->left;
                        Node* next_parent = new Node();
                        next_parent = current;
                        while (1)
                        {
                            // This we traverse till highest value is searched in left sub tree of current
                            if(next->right != NULL){
                                next_parent = next;
                                next = next->right;
                            }
                            else{

                                // VIMP NOTE
                                // This is if highest value of left sub tree of current have a left child
                                // Then we will point next_left_child to right child of next_parent
                                if(next->left != NULL){
                                    Node* next_left_child = new Node();
                                    next_left_child = next->left;
                                    next_parent->right = next_left_child;
                                }

                                // Pointing left and right child of current to next
                                next->left = current->left;
                                next->right = current->right;

                                // Pointing next to parents left or right child
                                if(parent->left == current){
                                    parent->left = next;
                                }
                                else{
                                    parent->right = next;
                                }

                                // Deleting current and Break the Infinite while loop
                                delete current;
                                break;
                            }
                        }
                    }

                    //This means deleting node is non leaf node having either left or right node but not both
                    // So, simply point next node to parent current node
                    else{

                        // Checking if non leaf node have either left or right node
                        if(current->left != NULL){
                            next = current->left;
                        }
                        else{
                            next = current->right;
                        }

                        // Pointing next node to parent current node
                        if(parent->left == current){
                            parent->left = next;
                        }
                        else{
                            parent->right = next;
                        }
                        delete current;
                    }

                    cout<<"Keyword \""<<k<<"\" is Deleted form Dictionary."<<endl;
                    return ;
                }

                // Keyword is not yet Searched in Dictionary
                // This will traverse till current becomes equal to NULL
                else{
                    parent = current;
                    if(current->keyword > k){
                        current = current->left;
                    }
                    else{
                        current = current->right;
                    }
                }
            }

            // Required Keyword is not Present in Dictionary
            cout<<"Keyword \""<<k<<"\" is Not Present in Dictionary."<<endl;
        }

        // This will read keyword from dictionary
        // If keyword is present in dictionary --> return number of comparisons required to find or read keyword
        // Else --> return 0
        void search_keyword(string k){
            Node* current = root;

            // This variable will calculate number of comparison required to Search the keyword in Dictionary
            int comparison = 0;
            while (current != NULL)
            {
                comparison++;
                // Keyword is Searched in Dictionary
                if(current->keyword == k){
                    cout<<"Keyword \""<<k<<"\" with Meaning \""<<current->meaning<<"\" is Present in Dictionary."<<endl;
                    cout<<comparison<<" Comparison are required to Find keyword \""<<k<<"\" from Dictionary."<<endl;
                    return ;
                }

                // Keyword is not yet Searched in Dictionary
                // This will traverse till current becomes equal to NULL
                else{
                    if(current->keyword > k){
                        current = current->left;
                    }
                    else{
                        current = current->right;
                    }
                }
            }

            // Required Keyword is not Present in Dictionary
            cout<<"Keyword \""<<k<<"\" is Not Present in Dictionary."<<endl;
        }

        // This will display keywords in ascending order of keywords
        // This is simple inorder traversal of BST
        void ascending_keywords(Node* current){
            if(current != NULL){
                ascending_keywords(current->left);
                cout<<current->keyword<<" ---> "<<current->meaning<<endl;
                ascending_keywords(current->right);
            }
        }

        // This will display keywords in descending order of keywords
        // This is simple inorder traversal of swapped node BST
        void descending_keywords(Node* current){
            swapping_nodes(current);
            ascending_keywords(current);
            swapping_nodes(current);
        }

        // This will swap the left child and right child node of parent node
        void swapping_nodes(Node* current){
            Node* temp;
            if(current != NULL){
                swapping_nodes(current->left);
                swapping_nodes(current->right);

                // Swapping nodes of current node
                temp = current->left;
                current->left = current->right;
                current->right = temp;
            }
        }
};

int main(){
    Dictionary D;
    string keyword;

    // Menu for Operations of Dictionary
    while (1)
    {
        cout<<"\n1. Add New Keyword."<<endl;
        cout<<"2. Search Keyword."<<endl;
        cout<<"3. Update Meaning of Keyword."<<endl;
        cout<<"4. Delete Keyword."<<endl;
        cout<<"5. Display of Keywords in Ascending Order."<<endl;
        cout<<"6. Display of Keywords in Descending Order."<<endl;
        cout<<"7. Exit.\n"<<endl;

        int choice;
        // Reading choice from user
        cout<<"Enter your choice from Above Menu : ";
        cin>>choice;

        if(choice >= 1 && choice <= 4){
            cout<<"Enter Keyword : ";
            cin>>keyword;
            int len = keyword.length();

            // Converting keyword to lowercase
            for (int i = 0; i < len; i++)
            {
                keyword[i] = tolower(keyword[i]);
            }

            if(choice == 1) D.add_keyword(keyword);
            else if(choice == 2) D.search_keyword(keyword);
            else if(choice == 3) D.update_meaning(keyword);
            else D.delete_keyword(keyword);
        }
        else if(choice == 5){
            cout<<"\nKeywords and their meaning in Ascending Order : "<<endl;
            D.ascending_keywords(D.get_root());
        }
        else if(choice == 6){
            cout<<"\nKeywords and their meaning in Descending Order : "<<endl;
            D.descending_keywords(D.get_root());
        }
        else if(choice == 7){
            cout<<"Program Exit."<<endl;
            break;
        }
        else{ // Invalid Choice
            cout<<"Enter a valid choice."<<endl;
        }
    }

    return 0;
}