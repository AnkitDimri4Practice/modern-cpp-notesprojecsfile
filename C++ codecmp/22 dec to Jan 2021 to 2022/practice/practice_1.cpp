#include<iostream>
using namespace std;
class PrintJob{
    int nPages_;
    public:
    static int nTrayPages_;
    static int nJob_;
    PrintJob(int nP):nPages_(nP){
        ++nJob_;cout << "Printing : " << nP << " pages\n";
        nTrayPages_ = nTrayPages_ - nP; 
    }
    ~PrintJob(){
        --nJob_;
    }
};
int PrintJob::nTrayPages_ = 600;
int PrintJob::nJob_ = 0;
int main(){
    cout << "Jobs : " << PrintJob::nJob_;
    cout << "\nPages : " << PrintJob::nTrayPages_ << "\n";
    PrintJob job1(20);
    cout << "Jobs : " << PrintJob::nJob_;
    cout << "\nPages : " << PrintJob::nTrayPages_ << "\n";
    {
        PrintJob job1(40), job2(50),job3(100);
        cout << "Jobs : " << PrintJob::nJob_;
        cout << "\nPages : " << PrintJob::nTrayPages_ << "\n";
        PrintJob::nTrayPages_ += 400;
    }
    cout << "Jobs : " << PrintJob::nJob_;
    cout << "\nPages : " << PrintJob::nTrayPages_ << "\n";
}