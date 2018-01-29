#include <iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

class linkedlist{
	node *head,*tail;
	public:
	linkedlist(){
		head = NULL;
		tail = NULL;
	}
	
	void addNode(int num){
		node * temp = new node;
		temp->next = NULL;
		temp->data = num;
		if(head == NULL){
			head = temp;
			tail = temp;
		}
		else{
			tail->next = temp;
			tail = temp;
		}
		cout<<"new element added"<<temp->data<<endl;
	}
	
	int peepFront(){
		return head->data;
	}
	
	int peepTail(){
		return tail->data;
	}
	
	int popFront(){
		int ret = head->data;
		node *del = head;
		head = head->next;
		delete del;
		return ret;		
	}
	
	int popTail(){
		node *temp = head;
		int ret = tail->data;
		while(temp->next->next != NULL){
			temp = temp->next;
		}
		tail = temp;
		tail->next =NULL;
		delete temp->next;
		return ret;
	}
	
	void removeHead(){
		node *temp = head;
		head = head->next;
		delete temp;
	}
	
	void removeTail(){
		node *temp = head;
		while(temp->next->next != NULL){
			temp = temp->next;
		}
		tail = temp;
		tail->next = NULL;
		delete temp->next;
	}
	
	void display(){
		node *temp = head;
		while(temp !=NULL){
			cout<<temp->data<<"\t";
			temp = temp->next;
		}
		cout<<endl;
	}
	
	node *getHead(){
		return head;
	}
	
	node *getTail(){
		return tail;
	}
	
	bool isEmpty(){
		if(head==NULL) return true;
		else return false;
	}

};

class Graph{
	int V;
	linkedlist *adj_list;
	public:
	Graph(int V);//graph constructor
	void addEdge(int x, int y);//to add edge to the graph from x to y
	void addSymEdge(int x, int y);
	void BFS(int start);
	void display();
};

Graph::Graph(int V){
	this->V = V;
	adj_list = new linkedlist[V];
}

void Graph::addEdge(int x, int y){
	adj_list[x].addNode(y);
}

void Graph::addSymEdge(int x, int y){
	adj_list[x].addNode(y);
	adj_list[y].addNode(x);
}

void Graph::BFS(int start){
	bool *visited = new bool[V];
	for(int i=0;i<V;i++){
		visited[i] = false;
	}
	
	linkedlist queue;
	queue.addNode(start);
	visited[start] = true;
	
	while(!queue.isEmpty()){
		int nextNode = queue.popFront();
		cout<<"next node = "<<nextNode<<endl;
		cout<<nextNode<<endl;
		node *temp = adj_list[nextNode].getHead();
		while(temp != NULL){
			if(visited[temp->data]==false){
				visited[temp->data] = true;
				queue.addNode(temp->data);
			}
			temp = temp->next;
		}
	}
	
	
}

void Graph::display(){
	for(int i=0;i<V;i++){
		node *temp = adj_list[i].getHead();
		while(temp !=NULL){
			cout<<temp->data<<"\t";
			temp = temp->next;
		}
		cout<<endl;
	}
	
}

int main(){
	cout<<"program starts\n\n";
	linkedlist lst;
	lst.addNode(1);
	lst.addNode(3);
	lst.addNode(5);
	lst.addNode(7);
	lst.addNode(9);
	lst.addNode(11);
	cout<<"head of lst"<<lst.getHead()<<endl<<endl;
	node *h = lst.getHead();
	cout<<"h="<<h<<endl;
	
	cout<<"first disp\n";
	lst.display();
	cout<<"first disp end\n";
	lst.popFront();
	lst.display();
	lst.popTail();
	lst.display();
	cout<<"\n\n graph stuff \n\n\n\n";
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.display();
    cout<<endl<<endl<<"printing bfs"<<endl<<endl;
    g.BFS(2);
	
	return 0;
	}
