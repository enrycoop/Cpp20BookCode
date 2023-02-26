
#include <iostream>
#include <iomanip>

void field_width(){
    using namespace std;

    cout << " N   N^2     N^3\n";
    for (int i{1}; i != 21; ++i)
        cout << setw(2) << i
        << setw(6) << i*i
        << setw(7) << i*i*i << '\n';

}

void fill_character(){
    using namespace std;

    int day{14};
    int month{3};
    int year{2006};
    int dollars{42};
    int cents{7};

    //Print date in USA order
    cout << "Date: " << setfill('0') << setw(2) << month //setfill si ricorda il carattere con cui riempire
            << '/' << setw(2) << day // mentre setw ogni volta che facciamo un output dobbiamo settarlo
            << '/' << setw(2) << year << '\n';
    cout << "Pay to the order of: CASH\n";
    cout << "The amount of $" << setfill('*') << setw(8) << dollars << '.'
            << setfill('0') << setw(2) << cents << '\n';
}

void alignment(){
    using namespace std;
    cout << '|' << setfill('*') << setw(6) <<  1234 << '|' << '\n';
    cout << '|' << left         << setw(6) <<  1234 << '|' << '\n';
    cout << '|' <<                    setw(6) << -1234 << '|' << '\n';
    cout << '|' << right        << setw(6) << -1234 << '|' << '\n';
}

void eq_alignment(){
    using namespace std;
    cout.fill('0');
    cout.width(6);
    cout << 42 << '\n';

    cout.setf(ios_base::left, ios_base::adjustfield);
    cout.width(6);
    cout << 42 << '\n';
    cout << 42 << '\n';
    cout.fill('-');
    cout.width(6);
    cout << -42 << '\n';
}

void by_myself(){
    using namespace std;
    cout << right;
    int constexpr low{1};
    int constexpr high{10};
    int constexpr colwidth{4};
    cout << setfill(' ') << setw(colwidth+1) << "*|";
    for(int i={low}; i<=high; ++i){
        cout << setw(4) << i;
    }
    cout << "\n";
    cout << setfill('-') << setw(colwidth+1) << "+" << setw((high-low + 1) * colwidth) << "-" << '\n';

    for(int i={low}; i<=high; ++i){
        cout << setfill(' ') << setw(colwidth) << i << "|";
        for(int j={low}; j<=high; ++j){
            cout << setw(colwidth) << i*j;
        }
        cout<<"\n";
    }
}

int main() {

    fill_character();
    std::cout << "------------------------------------------------------------------------------------------\n\n";

    alignment();
    std::cout << "------------------------------------------------------------------------------------------\n\n";

    eq_alignment();
    std::cout << "------------------------------------------------------------------------------------------\n\n";

    by_myself();
    std::cout << "------------------------------------------------------------------------------------------\n\n";



    return 0;
}
