17_Friend Function and Friend Class.cppModule Objectives 
    > Understand friend function and class 
        
    Module outline 
        2. Friend Function 
            > friend Function : Basic Notion 
                > Ordinary Function 
                    #include<iostream>
                    using namespace std;
                    class MyClass {
                        int data_;
                        public: 
                        MyClass(int i) : data_(i) { }
                    };
                    void display(const MyClass& a){ // gbl fun
                        cout << "Data : " << a.data_; // error 1: 
                    }
                    int main(){
                        MyClass obj(10);
                        display(obj);
                        return 0;
                    }
                        > display() is a non member function
                        > Error 1 : cannot access private member declared in class  

                > Friend Function 
                        #include<iostream>
                        using namespace std;
                        class MyClass {
                            int data_;
                            public: 
                            MyClass(int i) : data_(i) { }
                            friend void display(const MyClass& a);
                        };
                        void display(const MyClass& a){ // global function 
                            cout << "Data : " << a.data_;  // Okay 
                        }
                        int main(){
                            MyClass obj(10);
                            display(obj);
                            return 0;
                        }

                            > display() is a non-member function; but friend to class MyClass
                            > Able to access data_ even through it is private in class MyClass
                            > Output : data = 10  
           
            >  Friend Function : 
                        [Encapsulation is a way to restrict the direct access to some components of an Object, so users cannot access state values for all of the variables of a particular object.]
                            [Encapsulation can be used to hide both data members and data functions or Methods associated with an instantiated class or object.]
                                class {
                                    data members[variables] + Methods(behavior)[methods]
                                }
                > A friend function of a class 
                    > has access to the private and protected members of the class (breaks the encapsulation) in addition to public members 
                    > must have its prototype include within the scope of the class prefixed with the keyword friend 
                    > does not have its name qualified with the class scope 
                    > is not called with an invoking Object of the class 
                    > can be declared friend in more than one classes 
                > A friend function can be a 
                    > global function 
                    > a member function of a class 
                    > a function template 

            > Matrix - Vector Multiplication
                > 
                    > Multiply a Matrix with a Vector

                            #include<iostream>
                            using namespace std;
                            class Matrix; // Forward declaration 
                            class Vector {
                                int e_[4];int n_;
                                public:
                                Vector(int n) : n_(n){
                                    for(int i{0};i<n_;i++) // Arbitrary 
                                        e_[i] = i + 1;   // init 
                                }
                                void Clear_Format(){ // Set a zero vector 
                                    for(int i{0};i<n_;i++)
                                        e_[i] = 0;
                                }
                                void Show_Function(){
                                    for(int i{0};i<n_;i++)
                                        cout <<e_[i] << " ";
                                    cout << "\n\n";
                                }
                                friend Vector Prod(Matrix *pM, Vector *pV);
                            };
                            class Matrix {
                                int e_[3][3]; int m_,n_; public: 
                                Matrix(int m,int n) : m_(m),n_(n){  // Arbitration 
                                    for(int i{0};i<m_;i++)          // init
                                        for(int j{0};j<n_;j++) e_[i][j] = i + j;
                                }
                                void Show_Function(){   // Show the matrix 
                                    for(int i{0}; i<m_;i++){
                                        for(int j{0};j<n_;j++)
                                            cout << e_[i][j] << " ";
                                        cout << "\n";
                                    } cout << "\n";
                                }
                                friend Vector Prod(Matrix *pM, Vector *pV);
                            };
                            Vector Prod(Matrix *pM, Vector *pV){
                                Vector v(pM->m_); v.Clear_Format();
                                cout << "___________________\n\n";
                                for(int i{0}; i < pM->m_; i++)
                                    for(int j{0}; j < pM->n_;j++)
                                        v.e_[i] += pM->e_[i][j] * pV->e_[j];
                                return v;
                            }
                            int main(){
                                Matrix M(2,3);
                                Vector V(3);
                                Vector PV = Prod(&M,&V);
                                
                                M.Show_Function();
                                V.Show_Function();
                                PV.Show_Function();
                                cout << "___________________\n\n";
                                
                                return 0; 

                            }
                                > Vector Prod(Matrix*, Vector*); is a global function 
                                > Vector Prod(Matrix*, Vector*); is friend of class Vector as well as class Matrix 
                                > This function accesses the private data members of both these classes   

            > Linked List 
                > Linked List :
                        #include<iostream>
                        using namespace std;
                        class Node; // Forward declaration 
                        class List{
                            Node *head;
                            Node *tail;
                            public:
                            List(Node *h = 0) : head(h),tail(h){ }
                            void display();
                            void append(Node *p);
                        };
                        class Node {
                            int info;
                            Node *next;
                            public:
                            Node(int i) : info(i), next(0) { }
                            friend void List::display();
                            friend void List::append(Node *);
                        };
                        void List::display(){ // friend of Node 
                            Node *ptr = head;
                            while (ptr) {
                                cout << ptr->info << " ";
                                ptr = ptr->next;
                            }
                        }
                        void List::append(Node *p){     // Friend of node 
                            if(!head) head = tail = p;
                            else{
                                tail->next = p;
                                tail = tail->next;
                            }
                        } 
                        int main(){
                            List l;       // Init null list 
                            Node n1(1), n2(2), n3(3);   //few nodes 
                            l.append(&n1);  //add nodes to list 
                            l.append(&n2);
                            l.append(&n3);
                            l.display();    // Show list
                        }
                                > List is built on Node. Hence list needs to know the internals of Node
                                > void List::append(Node *); needs the internals of Node - Hence friend member function is used 
                                > void List::display(); needs the internals of Node - hence friend member function is used 
                                > We can do better with friend classes.                               

        3. Friend Class 
                > A friend class of a class 
                    > has access to the private and protected members of the class (breaks the encapsulation) in addition to public members 
                    > does not have its name qualified with the class scope(not a nested class)
                    > can be declared friend in more than one classes 
                > A friend class can be a 
                    > class 
                    > class template 
                    
            > linked List 
                >      #include<iostream>
                        using namespace std;
                        class Node;     // Forward declaration 
                        class List{
                            Node *head; // head of the list 
                            Node *tail; // tail of the list 
                            public:
                            List(Node *h = 0) : head(h), tail(h) { }
                            void display();
                            void append(Node *p);
                        };
                        class Node {
                            int info;       // Data of the node 
                            Node *next;     // Ptr to next node 
                            public:
                            Node(int i) : info(i), next(0) { }
                            // friend void list::display();
                            // friend void List::append(Node *);
                            friend class List;
                        };
                        void List::display(){
                            Node *ptr = head;
                            while (ptr) {
                                cout << ptr->info << " ";
                                ptr = ptr->next;
                            }
                        }
                        void List::append(Node *p) {
                            if(!head) head = tail = p;
                            else {
                                tail->next = p;
                                tail = tail->next;
                            }
                        }
                        int main(){     
                            List l;     // Init null list 
                            Node n1(1), n2(2), n3(3); // Few nodes
                            l.append(&n1);      // Add nodes to list 
                            l.append(&n2);
                            l.append(&n3);
                            l.display();    // Show list 
                        }

                            > List class is now a friend of Node class. hence it has full visibility into the internals of Node 
                            > When Multiple member functions need to be friends, it is better to use friend class. 
                           
            > Iterator 
                > 
                    #include<iostream>
                    using namespace std;
                    class Node;     // Forward declaration 
                    class List;
                    class Iterator {
                        Node *node; // Current Node  
                        List *list; // Current list 
                        public:
                        Iterator() : node(0), list(0) { }
                        void begin(List *); // Init
                        bool end();     // Check end 
                        void next();    // Go to next
                        int data();     // Get node next     
                    };
                    class List {
                        Node *head, *tail; 
                        public:
                        List(Node *h = 0) : head(h), tail(h) { }
                        void append(Node *p);
                        friend class Iterator;
                    };
                    class Node {
                        int info; Node *next; public:
                        Node(int i) : info(i), next(0){ }
                        friend class List;
                        friend class Iterator;
                    };
                    // Iterator Methods 
                    void Iterator::begin(List *l){ list = l; node = l->head; }  // set list & Init 
                    bool Iterator::end(){ return node==0; }
                    void Iterator::next(){ node=node->next; }
                    int Iterator::data(){ return node->info; }
                    void List::append(Node *p) {
                        if(!head)head = tail = p;
                        else {
                            tail->next = p; tail = tail->next;
                        }
                    }
                    int main(){     
                        List l;
                        Node n1(1), n2(2), n3(3);
                        l.append(&n1); l.append(&n2); l.append(&n3);
                        Iterator i;
                        for(i.begin(&l); !i.end(); i.next()){
                            cout << i.data() << " ";    // Iterator Loop
                        }
                    }
                        > An iterator now traverses over the elements of the list 
                        > void List::display() is dropped from List and can be written in main()
                        > List class is a friend of list and Node class 
                        > Iterator class is a friend of list and Node classes 
                        
        4. Properties of friend 
            >   
                > Friendship is neither commutative nor transitive 
                    > A is a friend of B does not imply that B is a friend of A 
                    > A is a friend of B and B is a friend of C does not imply that A is a friend of C 
                > visibility and Encapsulation
                    > public: a declaration that is accessible to all 
                    > protected: a declaration that is accesses only to the class itself and its subclasses 
                    > private: a declaration that is accessible only to the class itself 
                    > friend: a declaration that is accessible only to friend's of a class. friend tend to break data hiding and must be used judiciously. Like: 
                        > A function needs to access the internals of two (or more) independent classes (Matrix-vector Multiplication)
                        > A class is built on top of another (List-Node Access, List Iterator)
                        > Certian situations of operator overloading (like streming operators)  

        5. Comparison :: of friend vis-a-vis Member functions
            
            _________________________________________________________________________________________________________________________________________________________________
                                friend Functions                                    |                 static & Non-static Member functions
                > Declared using the keyword friend                                 | > Declared in private, public, or protected specifier 
                > Declared in one or more classes                                   | > Declared only in scope of a particular class 
                > Not a part of the class, not defined in the namespace of the      | > Part of the class definition, defined in the namespace of the class 
                classes                                                             | > Has access to all private, public, and protected members of its class, if not-static 
                > Has access to all private, public and protected members of        | > Has access to only private, public and protected static members of its class, if static 
                classes.                                                            | > Member function of the class 
                > Called with an object (non-static member), an object / a class    | > Called with an object (non-static members) or an object 
                (static member), or as a global function                            |   / a class (static member) of the defining class 
                > Does not have this pointer (of the class it accesses).            | > Has this pointer of the defining class, if a Non-static and no this pointer if static 
                needs the pointer to the object                                     |
                > Used in collaborative multi-class design                          | > Used for modularity and encapsulation 
                > Breaks encapsulation                                              | > Ensures encapsulation 
                > Binary operation usually takes two explicit parameters            | > Binary operations usually take only one explicit parameter 
                > Unary operator takes at least one explicit parameter              | > Unary operator does not take any explicit parameter 
            _________________________________________________________________________________________________________________________________________________________________

        
        6. Module Summary  
            > Introduced the notion of friend function
            > Introduced the notion of friend class 
            > Studied the use of friend function and friend class with examples 
            > friend Introduces visibility hole by breaking encapsulation - should be used with care 

        ___________________________________________________Complete______________________________________________________