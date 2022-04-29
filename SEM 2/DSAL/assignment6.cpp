/*
	Problem Statement :
	Represent a given graph using adjacency list to perform DFS and BFS.
	Use the map of the area around the college as the graph.
	Identify the prominent landmarks as nodes and perform DFS and BFS on that.
*/

#include <iostream>
using namespace std;

int choice;

// Class Node
class Node{
	int data;
	Node* down;
	Node* next;

public:
	Node();
	Node(int);

	friend class Graph;
};

// Default Constructor
Node::Node(){
	data = 0;
	down = NULL;
	next = NULL;
}

// Parameterized Constructor
Node::Node(int d){
	data = d;
	down = NULL;
	next = NULL;
}

// class Graph
class Graph{
	Node* Head;
public:
	Graph();
	void insert_vertex();
	void insert_edge();
	void display_list();
};

// Default Constructor
// Set Head Node to NULL
Graph::Graph(){
	Head = NULL;
}

// Inserts the Vertex in Graph
// Exception Handling :
// 1. Also checks for unique Vertex in Graph
void Graph::insert_vertex(){
	while(1){
		cout<<"\nMenu."<<endl;
		cout<<"1. Add Vertex."<<endl;
		cout<<"2. Exit."<<endl;

		cout<<"\nEnter your choice : ";
		cin>>choice;

		if(choice == 1){
			cout<<"Enter vertex number : ";
			int vertex;
			cin>>vertex;
			if(Head == NULL){
				Head = new Node();
				Head->data = vertex;
			}
			else{
				Node *current = Head, *previous = current;
				bool flag = 0;
				while(current != NULL){
					if(current->data == vertex){
						flag = 1;
						break;
					}
					previous = current;
					current = current->down;
				}

				if(flag) cout<<"Vertex "<<vertex<<" is already present in Graph."<<endl;
				else {
					Node* new_node = new Node();
					new_node->data = vertex;
					previous->down = new_node;
					cout<<"Vertex "<<vertex<<" Inserted Successfully."<<endl;
				}
			}
		}

		else if(choice == 2){
			cout<<"Exit."<<endl;
			break;
		}

		// Invalid Choice
		else{
			cout << "Enter a valid choice." << endl;
		}
	}
}


// Inserts the Edge of Source Vertex
// Exception Handling :
// 1. Checks whether both Source and Destination Vertex Exist in Graph or Not
// 2. Insert only one edge between any Source and Destination Vertex.
void Graph::insert_edge(){
	while(1){
		cout<<"\nMenu."<<endl;
		cout<<"1. Insert Edges."<<endl;
		cout<<"2. Exit."<<endl;

		cout<<"\nEnter your choice : ";
		cin>>choice;

		if(choice == 1){
			Node* source_vertex = Head;
			int source;
			cout<<"Enter Source Vertex : ";
			cin>>source;

            // Checks whether Source Vertex Exist in Graph or Not
			bool source_flag = 0;
			while(source_vertex != NULL){
				if(source_vertex->data == source){
					source_flag = 1;
					break;
				}
				source_vertex = source_vertex->down;
			}

			if(source_flag){
				while(1){
                    cout<<"\nEnter Destination Vertices of Source Vertex "<<source<<endl;
					cout<<"1. Enter New Destination Vertex."<<endl;
					cout<<"2. Exit"<<endl;

					cout<<"Enter your choice : ";
					cin>>choice;

					if(choice == 1){
                        Node* destination_vertex = Head;
						int destination;
                        cout<<"Enter Vertex Number of Destination Vertex : ";
						cin>>destination;

                        // Checks whether Destination Vertex Exist in Graph or Not
                        bool destination_flag = 0;
						while(destination_vertex != NULL){
                            if(destination_vertex->data == destination){
                                destination_flag = 1;
                                break;
                            }
                            destination_vertex = destination_vertex->down;
						}

                        if(destination_flag){
                            Node *current = source_vertex, *previous = current;
                            bool already_present = 0;
                            while(current != NULL){
                                // current->data == destination ---> This will checks for unique edge between Source and Destination Vertex
                                // source != destination ---> This will allow a self loop or self edge of Source Vertex
                                if(current->data == destination and source != destination){
                                    already_present = 1;
                                    break;
                                }
                                previous = current;
                                current = current->next;
                            }
                            if(already_present) cout<<"This Edge is already Exist. Enter another Destination Vertex."<<endl; 
                            else previous->next = new Node(destination), cout<<"Edge Inserted Successfully."<<endl;
                        }
                        else cout<<"Destination Vertex "<<destination<<" Not Found in Graph."<<endl;
					}

					else if(choice == 2){
						cout<<"Exit."<<endl;
						break;
					}

					// Invalid Choice
					else{
						cout << "Enter a valid choice." << endl;
					}
				}
			}
			else cout<<"Source Vertex "<<source<<" Not Found in Graph."<<endl;
		}

        else if(choice == 2){
            cout<<"Exit."<<endl;
            break;
        }

        // Invalid Choice
        else{
            cout << "Enter a valid choice." << endl;
        }
	}
}

// Display Adjacency list
void Graph::display_list(){
	Node* column = Head;
	while(column != NULL){
		Node* row = column->next;
		cout<<column->data<<" --> ";
		while(row != NULL){
			cout<<row->data<<" --> ";
			row = row->next;
		}
		cout<<"NULL"<<endl;
		column = column->down;
	}
}

int main() {
	Graph G;
	G.insert_vertex();
    G.insert_edge();
	G.display_list();
	return 0;
}