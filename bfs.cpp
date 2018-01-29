#include <iostream>
using namespace std;

struct node{
	int data;
	struct node * next;
};


class linkedlist{
	//~ private:
	//~ node *head,*tail;
	public:
	node *head,*tail;
	linkedlist(){
		head = NULL;
		tail = NULL;
		}
	
	node * create_node(int node_data){
		node *temp =new node;
		temp->data = node_data;
		temp->next  =NULL;
		return temp;
	}
	
	void addNode(int new_data){
		//adds at the tail
		if(head==NULL){
			head = create_node(new_data);
			tail = head;			
		}
		else{
			node *temp = create_node(new_data);
			tail->next = temp;
			tail = temp;
		}
	}
	
	void removeFront(){
		if(head==tail){
			head = NULL;
			tail = NULL;
			//~ return NULL;
		}
		else{
			node *temp = new node;
			temp = head;
			head = temp->next;
			delete temp; 
			
		}
	}
	
	int head_val(){
		return head->data;
	}
	
	bool isEmpty(){
		if(head==NULL){
			return true;
		}
		else{
			return false;
		}
	}
	
	void display(){
		node *temp = head;
		while(temp != NULL){
			cout<<temp->data<<"\t";
			temp = temp->next;
		}
	}
	
};

class Graph{
	int V;
	linkedlist * adj_list;
	public:
	Graph(int V);//graph constructor
	void add_edge(int x, int y);//to add edge to the graph from x to y
	void BFS(int start);
	void display();
};

Graph::Graph(int V){
	this->V = V;
	adj_list = new linkedlist[V];
	
}

void Graph::add_edge(int x, int y){
	adj_list[x].addNode(y);//outgoing edge from x to y
}

void Graph::display(){
	cout<<endl<<"new one"<<endl;
	for(int i=0;i<V;i++){
		adj_list[i].display();
		cout<<endl;
	}
}

void Graph::BFS(int start){
	bool *visited = new bool[V];// to rempve loop
	
	for(int i=0;i<V;i++){//make true of visited
		visited[i] = false;
	}
	
	linkedlist queue;
	visited[start] = true;
	queue.addNode(start);
	
	int val=0;
	//~ cout<<"entering while loop in bfs \n\n";
	while(!queue.isEmpty()){
		val = queue.head_val();
		cout<<val<<" ";
		queue.removeFront();
		
		node* temp = adj_list[val].head;
		while(temp !=NULL){
			//~ cout<<"inside inner while loop\n";
			if(visited[temp->data] == false){
				queue.addNode(temp->data);
				visited[temp->data] = true;
			}
			temp = temp->next;
		}
		
		
	}
}

int main() 
{
    //cout << "Hello, World!";
    //linkedlist a;
    //a.addNode(5);
    //a.addNode(10);
    //a.addNode(15);
    //a.addNode(20);
    //a.display(); 
	Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
    g.display();
    cout<<endl<<endl<<"printing bfs"<<endl<<endl;
    g.BFS(2);
    
    return 0;
}
