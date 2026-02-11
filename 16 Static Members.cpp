Module Outline : 
    1. static Data Member 
    static Data Member  
        > A static data member 
            > is associated with class not with object 
            > is shared by all the objects of a class 
            > needs to be defined outside the class scope (in addition to the declaration within the class scope) to avoid linker error 
            > must be initialized in a source file 
            > is constructed before main() starts and destructed after main() ends 
            > can be private / public 
            > can be accessed 
                > with the class-name followed by the scope resolution operator (::)
                > as a member of any object of the class 
            > virtually eliminates any need for global variables in OOPs environment 
        > We illustrate first with a simple example and then with a Print Task where: 
            > There is a printer which can be loaded with a paper from time to time 
            > Several print jobs (each requiring a number of pages) may be fired on the printer 
        
        > Example
            > Static Data Member: Example 
                > Non static data member 
                    #include<iostream>
                    using namespace std;
                    class Myclass{
                        int x;
                        public: 
                        void get(){
                            x = 15;
                        }
                        void print(){
                            x = x + 10;
                            cout << "x : " << x << "\n";
                        }
                    };
                    int main(){
                        Myclass obj_1,obj_2;
                        obj_1.get(); obj_2.get();
                        obj_1.print(); obj_2.print();
                    }
                    x : 25
                    x : 25 
                        > x is non-static data member 
                        > x cannot be shared between obj_1 and obj_2
                        > Non-static data members do not need seperate definitions- instantiated with the object 
                        > Non static data members are initialized during object construction 
            
            > static Data Member 
                #include<iostream>
                using namespace std;
                class Myclass{
                    static int x; // Declare static 
                    public: 
                    void get(){
                        x = 15;
                    }
                    void print(){
                        x = x + 10;
                        cout << "x : " << x << " ";
                    }
                };
                int Myclass::x = 0; // Define static data member 
                int main(){
                    Myclass obj_1,obj_2; // Have same x 
                    obj_1.get(); obj_2.get();
                    obj_1.print(); obj_2.print();
                }
                x : 25, x : 35
                    > x is static data member 
                    > x is shared by all Myclass object including obj_1 & obj_2 
                    > static data members must be defined in the global scope 
                    > static data members are initialized during program startup 

        > Print Task 
            static Data Member: 
                print task(unsafe)
                        #include<iostream>
                        using namespace std;
                        class PrintJob{
                            int nPages_; /* # of pages in current job */
                            public: 
                            static int nTrayPages_; /* # of pages in the tray */
                            static int nJob_; // # of print jobs executing 
                            PrintJob(int nP):nPages_(nP) {
                                ++nJob_; cout << "Printing : " << nP << " pages" << "\n";
                                nTrayPages_ = nTrayPages_ - nP;
                            }
                            ~PrintJob() {
                                --nJob_; 
                            }
                        };
                        int PrintJob::nTrayPages_ = 500; // Definition and initialization -- load paper 
                        int PrintJob::nJob_ = 0;    // Definition and initialization -- no job to start with 
                        int main(){
                            cout << "Jobs : " << PrintJob::nJob_ << "\n";
                            cout << "Pages : " << PrintJob::nTrayPages_ << "\n";
                            PrintJob job1(10); 
                            cout << "jobs : " << PrintJob::nJob_ << "\n";
                            cout << "Pages : " << PrintJob::nTrayPages_ << "\n";
                            {
                                PrintJob job1(30),job2(20); // Different job1 in block scope 
                                cout << "Jobs : " << PrintJob::nJob_ << "\n";
                                cout << "Pages : " << PrintJob::nTrayPages_ << "\n";
                                PrintJob::nTrayPages_ += 100;   // Load 100 more pages 
                            }
                            cout << "jobs : " << PrintJob::nJob_ << "\n";
                            cout << "Pages : " << PrintJob::nTrayPages_ << "\n";
                        }
                        Jobs : 0   
                        Pages : 500
                        Printing : 10 pages
                        jobs : 1           // same nJob_, nTrayPages_
                        Pages : 490        
                        Printing : 30 pages
                        Printing : 20 pages
                        Jobs : 3        // same nJob_, nTrayPages_
                        Pages : 440        
                        jobs : 1        // same nJob_, nTrayPages_
                        Pages : 540 

                
                    #include<iostream>
                    using namespace std;
                    class PJ{
                        int np;public:
                        static int nT; static int nJ;
                        PJ(int n): np(n){
                            ++nJ;cout << "\nprinting : " << n << " pages\n";
                            nT = nT - n;
                        }
                        ~PJ(){
                            --nJ;
                        }
                    };
                    int PJ::nT = 500;
                    int PJ::nJ = 0;
                    int main(){
                        cout<< "\nJobs : " << PJ::nJ;
                        cout << "\nPages : " << PJ::nT << "\n";
                        PJ j(10);
                            cout<< "\nJobs : " << PJ::nJ;
                        cout << "\nPages : " << PJ::nT << "\n";
                        {
                            PJ j(30),j1(50);
                            cout<< "\nJobs : " << PJ::nJ;
                            cout << "\nPages : " << PJ::nT << "\n";
                        }
                        cout<< "\nJobs : " << PJ::nJ;
                        cout << "\nPages : " << PJ::nT << "\n";
                    }


        > Order of Initialization 
                Order of Initialization : Order of 
                    >   #include<iostream>
                        #include<string>
                        using namespace std;
                        class Data {
                            string id_; 
                            public: 
                            Data(const string& id) : id_(id){
                                cout << "Construct : " << id_ << "\n";
                            }
                            ~Data(){
                                cout << "Destruct : " << id_ << "\n";
                            }
                        };
                        class Myclass{
                            static Data d1_; // Listed 1st 
                            static Data d2_; // Listed 2nd 
                        };
                        Data Myclass::d1_("obj_1"); // Constructed 1st 
                        Data Myclass::d2_("obj_2"); // Constructed 2nd 
                        int main(){}
                            Construct : obj_1
                            Construct : obj_2
                            Destruct : obj_2 
                            Destruct : obj_1

            > 
                #include<iostream>
                #include<string>
                using namespace std;
                class Data {
                    string id_; public: 
                    Data(const string& id) : id_(id){
                        cout << "Constructed : " << id_ << "\n";
                    }
                    ~Data(){
                        cout << "Destructed : " << id_ << "\n";
                    }
                };
                class Myclass{
                    static Data d2_; // Order of static members swapped 
                    static Data d1_;
                };
                Data Myclass::d1_("obj_1"); // Constructed 1st 
                Data Myclass::d2_("obj_2");// Constructed 2nd 
                int main(){ }
                        Constructed : obj_1
                        Constructed : obj_2
                        Destructed : obj_2
                        Destructed : obj_1

                    > Order of initialization of static data members does not depend  on their order in the definition of the class. It depends on the order their definition and initialization in the source. 
                                           

    2. static Member function 
            > A static member function 
                > does not have this pointer - not associated with any object 
                > cannot access non-static members functions 
                > can be accessed 
                    > With the class - name followed by the scope resolution operator(::)
                    > as a member of any object of the class 
                > is needed to read / Write static data members 
                    > Again, for encapsulation Static data members should be private 
                    > get() - set() idiom is built for access (static member functions in public)
                > may initialize static data members even before any object creation 
                > cannot co-exist with a non-static version of the same function 
                > cannot be declared as const 
            > We repeat the print task with better (safer) modeling and coding..
            
        > print Task 
            Program : static Data & member Function:  Print Task(safe)
                    //  #include<iostream>  using namespace std
                        #include<iostream>
                        using namespace std;
                        class PJ{
                            int np; // # of pages in current job
                            static int nT; // Of pages in the tray 
                            static int nJ; // of print jobs executing 
                            public:
                            PJ(int n): np(n){
                                ++nJ;cout << "\nprinting : " << n << " pages\n";
                                nT = nT - n; // job started 
                            }
                            ~PJ(){
                                --nJ; // job done 
                            }
                            static int getJobs(){
                                return nJ; // get on nJ. Readonly No set provided 
                            }
                            static int checkPages(){
                                return nT; // Get on nT
                            }
                            static void loadPages(int n){
                                nT += n; // set on nT
                            }
                        };
                        int PJ::nT = 500; // Definition and initialization -- load paper 
                        int PJ::nJ = 0; /// Definition and initialization -- no job to start with 
                        int main(){
                            cout<< "\nJobs : " << PJ::getJobs;
                            // cout << "\nPages : " << PJ::nT << "\n";
                            cout << "\nPGES : " << PJ::checkPages() << "\n";
                            PJ j(10);
                            cout<< "\nJobs : " << PJ::getJobs;
                                // cout<< "\nJobs : " << PJ::nJ;
                            // cout << "\nPages : " << PJ::nT << "\n";
                            cout << "\nPGES : " << PJ::checkPages() << "\n";
                            {
                                PJ j(30),j1(50); // Diffferent j in block scope 
                                // cout<< "\nJobs : " << PJ::nJ;
                                cout<< "\nJobs : " << PJ::getJobs;
                                // cout << "\nPages : " << PJ::nT << "\n";
                                cout << "\nPGES : " << PJ::checkPages() << "\n";
                                PJ::loadPages(200);
                            }
                            // cout<< "\nJobs : " << PJ::nJ;
                            cout<< "\nJobs : " << PJ::getJobs;
                            // cout << "\nPages : " << PJ::nT << "\n";
                            cout << "\nPGES : " << PJ::checkPages() << "\n";
                        }

                    Jobs : 1
                    PGES : 500

                    printing : 10 pages 

                    Jobs : 1 // Same nJ , nT
                    PGES : 490

                    printing : 30 pages

                    printing : 50 pages

                    Jobs : 1 // Same nJ , nT
                    PGES : 410

                    Jobs : 1    // Same nJ , nT
                    PGES : 610

        > Count Objects 
                > We illustrate another example and use for static data members and member function 
                    > Here we want to track the number of objects created and destroyed for a class at any point in the program 
                    > Naturally no object can keep this information. So we hold two static data members 
                        > nObjCons_: Number of objects created since beginning. It is read-only and incremented in every constructor 
                        > nObjDes_: Number of objects destroyed since beginning. It is read-only and incremented in the destructor 
                    > At any point (nObjCons_ - nObjDes_) gives the number of live objects 
                    > In an alternate (less informative model) we may just maintain static data member nLive_ which is incremented in every constructor and decremented in the destructor 

            > count program : 
                    #include<iostream>
                    #include<string>
                    using namespace std;
                    class Myclass{
                        string id_; // Object ID
                        static int nObjCons_, nObjDes_; // object history 
                        public:
                        Myclass(const string& id) : id_(id){
                            ++nObjCons_;
                            cout << "Ctor : " << id_ << " "; getObjLive();
                        }
                        ~Myclass(){
                            ++nObjDes_;
                            cout << "Dtor : " << id_ << " ";getObjLive();
                        }
                        static int getObjConstructed(){
                            return nObjCons_;
                        }
                        static int getObjDestructed(){
                            return nObjDes_;
                        }// Get number of live objects 
                        static int getObjLive(){
                            int nLive = nObjCons_ - nObjDes_;
                            cout << "Live Objects : " << nLive << "\n";
                            return nLive;
                        }
                    };
                    int Myclass::nObjCons_ = 0;
                    int Myclass::nObjDes_ = 0;
                    int d1(Myclass::getObjLive());
                    Myclass sObj("sObj");
                    int d2(Myclass::getObjLive());
                    int main(){
                        Myclass::getObjLive();
                        Myclass aObj("aObj");
                        Myclass *dObj = new Myclass("dObj");
                        {
                            Myclass bObj("bObj");
                            delete dObj;
                        }
                        Myclass::getObjLive();
                    }

                        >   Live Objects : 0
                                Ctor : sObj Live Objects : 1
                                Live Objects : 1
                                Live Objects : 1
                                Ctor : aObj Live Objects : 2
                                Ctor : dObj Live Objects : 3
                                Ctor : bObj Live Objects : 4
                                Dtor : dObj Live Objects : 3
                                Dtor : bObj Live Objects : 2
                                Live Objects : 2
                                Dtor : aObj Live Objects : 1
                                Dtor : sObj Live Objects : 0

                
    3. Comparsion 
                Comparsion of static vis-a-vis non-static
        __________________________________________________________________________________________________________________________________________________________
                    static Data Members                                     |           Non- static Data Members 
        > Declared using keyword static                                     | > Declared witout using keyword static  
        > All objects of a class share the same copy / instance             | > Each object of the class gets its own copy / instance 
        > accessed using the class name or object                           | > Accessed only through an object of the class 
        > May be public or private                                          | > May be public or private 
        > belongs to the namespace of the class                             | > Belongs to the namespace of the class 
        > May be const                                                      | > May be const 
        > Are constructed before main() is invoked                          | > Are constructed during object construction 
        > Are destructed after (in reverse order) main() returns            | > Are destructed during object destruction 
        > Are constructed in the order of definitions in source             | > Are constructed in the order of listing in the class 
        > Has a lifetime encompassing main()                                | > Has a lifetime as of the lifetime of the object 
        > Allocated in static memory                                        | > Allocated in static , stack, or heap memory as of the object 
    ______________________________________________________________________________________________________________________________________________________________
    ______________________________________________________________________________________________________________________________________________________________
                    static Members Functions                                |           Non- static Members  Functions 
        > Declared using keyword static                                     | > Declared witout using keyword static  
        > Has no this pointer parameter                                     | > Has an implicit this pointer parameter 
        > invoked using the class name or object                            | > invoked only through an object of the class 
        > May be public or private                                          | > May be public or private 
        > Belongs to the namespace of the class                             | > Belongs to the namespace of the class
        > Can access static data members and methods                        | > Can access static data members and methods
        > cannot access non-static data members or methods                  | > can access non-static data members or methods
        > Can be invoked anytime during program execution                   | > Can be incoked only during lifetime of the object 
        > Cannot be virtual or const                                        | > May be virtual and / or const  
        > Constructor is static through not declared static                 | > Three cannot be a non-static constructor  
    ______________________________________________________________________________________________________________________________________________________________

    4. Singleton Class 
        > Singleton is a creational design pattern 
            > ensures that only one object of its kind exits and 
            > provides a single point of access to it for any other code 
        > A class is called a Singleton if it satisfies the above conditions
        > Many classes are Singleton: 
            > President of India 
            > prime Minitster of India 
            > director of IIT Kharagpur 
            > CEO of a Company 
            > .....
        > How to implement a Singleton class? 
        > How to restrict that user can created only one instsance ? 
         
            > static Data & Member Function Singleton Printer 
                    #include<iostream>
                    using namespace std;
                    class printer{ // This is a singleton printer -- only one instance 
                        private: bool blackAndWhite_, bothSided_;
                        printer(bool bw = false, bool bs = false):blackAndWhite_(bw),bothSided_(bs){
                            cout << "Printer Constructed : \n";  // private -- printer cannot be constructed! 
                        }
                        static printer *myprinter_; // pointer to the instance of the singleton printer 
                        public:
                        ~printer(){
                            cout << "Printer destructed : \n";
                        }
                        static const printer& printer_(bool bw = false, bool bs = false){ // Access the printer 
                            if(!myprinter_)myprinter_ = new printer(bw,bs);     // Constructed for first call 
                            return *myprinter_;                         // Reused from next time 
                        }
                        void print(int nP)const{
                            cout << "\nPrinting : " << nP << " pages\n";
                        }
                    };
                    printer *printer::myprinter_ = 0;
                    int main(){
                        printer::printer_().print(10);
                        printer::printer_().print(20);
                        delete &printer::printer_();
                    }
                            Printer Constructed : 

                            Printing : 10 pages

                            Printing : 20 pages
                            Printer destructed :
 
            > using function-local static Data Singleton Printer 
                >       #include<iostream>
                        using namespace std;
                        class printer{ // This is a singleton printer -- only one instance 
                            bool blackAndWhite_, bothSided_;
                            printer(bool bw = false, bool bs = false):blackAndWhite_(bw),bothSided_(bs){
                                cout << "Printer Constructed : \n"; 
                            }
                            ~printer(){cout << "\nprinter destructed\n";}
                            public:
                            static const printer& printer_(bool bw = false, bool bs = false){
                                static printer myprinter_(bw,bs); // the singleton --- constructed the first time 
                                return myprinter_;
                            }
                            void print(int nP)const{
                                cout << "\nPrinting : " << nP << " pages\n";
                            }
                        };
                        int main(){
                            printer::printer_().print(10);
                            printer::printer_().print(20);
                        }
                                Printer Constructed : 

                                Printing : 10 pages

                                Printing : 20 pages

                                printer destructed

                    > Function local static object is used 
                    > No memory management overhead - so destructor too get private 
                    > This is called meyer's Singleton

    5. Module Summary 
            > Introduced static data member 
            > Introduced static member function 
            > Exposed to use of static members 
            > Singleton class discussed 

    ________________________________________________The Complete_______________________________________________