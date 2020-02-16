#include <iostream>
#include "Bstope.h"
using namespace std;

int main()
{
	Bstope <int> b1;
	b1.insert(36);
	b1.insert(64);
	b1.insert(43);
	b1.insert(29);
	b1.insert(47);
	b1.insert(28);
	b1.insert(50);
	b1.insert(76);
	b1.insert(50);

	cout << "-------------- Creating BST using generics ----------------" << endl;
	cout << "\nThe height of the node (50) is: " << b1.getheight(50) << endl;
	cout << "\nLeftmost Cousin of (47) is: " << b1.leftSibling(47) << endl;
	cout << "\nRightmost Cousin of (50) is: " << b1.RightSibling(50) << endl;
	cout << "\nMaximum Sum of the brunch: " << b1.MaximumSum() << endl;
	cout << "\nMinimum Sum of the brunch: " << b1.MinimumSum() <<endl;
	cout << "\n-------------- end --------------" << endl;
}