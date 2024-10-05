#include <iostream>
#include <sstream>

using namespace std;

class linked_list {
public:
    linked_list() {}
    ~linked_list() { delete sentinal; }

    void insert_at_head(int val) {
        node *n = new node {val, sentinal->next};
        sentinal->next = n;
        size += 1;
    }

    void insert_at_n(int val, unsigned ix) {
        if (ix > size) {
            cout << "insert fail" << endl; return;
        }
        auto iter = sentinal;
        while (ix != 0) {
            iter = iter->next; ix -= 1;
        }
        auto tmp = iter->next;
        iter->next = new node {val, tmp};
        size += 1;
        cout << "insert OK" << endl;
    }
    
    int get(unsigned ix) const {
        if (ix >= size) {
            cout << "get fail" << endl;
            return -1;
        }
        auto iter = sentinal->next;
        while (ix != 0) {
            iter = iter->next; ix -= 1;
        }
        return iter->val;
    }

    void remove(unsigned ix) {
        if (ix >= size) {
            cout << "delete fail" << endl;
            return;
        }
        auto iter = sentinal;
        while (ix != 0) {
            iter = iter->next; ix -= 1;
        }
        auto tmp = iter->next;
        iter->next = iter->next->next;
        delete tmp;
        size -= 1;
        cout << "delete OK" << endl;
    }

    void show() const {
        if (size == 0) {
            cout << "Link list is empty" << endl;
            return;
        }
        for (auto iter = sentinal->next; iter != nullptr; iter = iter->next) {
            cout << iter->val;
            if (iter->next != nullptr) cout << " ";
        }
        cout << endl;
    }

private:
    struct node {
        int val;
        node *next;
    };
private:
    node *sentinal {new node {-1, nullptr}};
    unsigned size {0};
};

int main(int, char const *[]) {
    linked_list lst;
    int n; cin >> n;
    while (n--) {
        int val; cin >> val; lst.insert_at_head(val);
    }
    cin >> n; getchar();
    while (n--) {
        string oper; getline(cin, oper);
        if (oper == "show") {
            lst.show();
        } else if (oper.rfind("get", 0) == 0) {
            unsigned ix = stoi(oper.substr(4)) - 1;
            cout << lst.get(ix) << endl;
        } else if (oper.rfind("delete", 0) == 0) {
            unsigned ix = stoi(oper.substr(7)) - 1;
            lst.remove(ix);
        } else if (oper.rfind("insert") == 0) {
            string tmp = oper.substr(7);
            stringstream converter;
            converter << tmp;
            int ix, val;
            converter >> ix >> val;
            ix -= 1;
            lst.insert_at_n(val, ix);
        }
    }
    return 0;
}