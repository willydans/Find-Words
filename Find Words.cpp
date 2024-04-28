#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> matrix = {
    "AAFLKHPFSSUFICICLESGNNH",
    "SFVREOMRWLRTTSXOQQNAOAO",
    "QEIAIFXAEIRFVFYSXIMINJI",
    "WSTRLGOCAPBIAFIWIWTUACM",
    "FEYAEAISTPCRLUJKOAKCERS",
    "RVDAKPNDEEHDEMSNCKKFOAH",
    "MRNEDSLCRRIWNRSAAFITMMI",
    "YAAECIEAHYMOTAVHRSSTISB",
    "RJSEWELCCENNIETOHWSGLSE",
    "ATANYYMOIEESNESIOIRELTR",
    "UTENEWEBHMYBETNNRAIEBEN",
    "RCLKUTEAEQJLSGSHTGDSKOA",
    "BHOICATNRRSDDECEHOOLGIT",
    "ENSLUARIRSETALOCOHCTOHE",
    "FZFUDQJYMADOYIWYGLOVESU",
    "TEKALFWONSNAEBMIEJTZNTG",
    "ESWPOSJXEUTAYOZUWAKEZHM",
    "KZUHBPEZEERFLMSNOWBALLH",
    "NSNOWBOARDYTVWYCLEVOHSA",
    "ACOCRQLGZIYCHODRAZZILBI",
    "LBVKKWANZAAQINWOLPWONSL",
    "BFREEZINGRAINSLILGTMELT",
    "HQPYLWHFMNFFUFPSWXNUMMV",
};

bool searchWord(string word) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int len = word.size();

    // Cari secara horizontal
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j <= cols - len; ++j) {
            if (matrix[i].substr(j, len) == word)
                return true;
        }
    }

    // Cari secara vertikal
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i <= rows - len; ++i) {
            string colString = "";
            for (int k = i; k < i + len; ++k) {
                colString += matrix[k][j];
            }
            if (colString == word)
                return true;
        }
    }

    // Cari secara diagonal (maju)
    for (int i = 0; i <= rows - len; ++i) {
        for (int j = 0; j <= cols - len; ++j) {
            string diagString = "";
            for (int k = 0; k < len; ++k) {
                diagString += matrix[i + k][j + k];
            }
            if (diagString == word)
                return true;
        }
    }

    // Cari secara diagonal (mundur)
    for (int i = 0; i <= rows - len; ++i) {
        for (int j = len - 1; j < cols; ++j) {
            string diagString = "";
            for (int k = 0; k < len; ++k) {
                diagString += matrix[i + k][j - k];
            }
            if (diagString == word)
                return true;
        }
    }
    return false;
}

int main() {
    int N;
    cout << "Masukkan jumlah kata yang ingin dicari: ";
    cin >> N;
    vector<string> words(N);
    cout << "Masukkan kata-kata yang ingin dicari:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }

    cout << "Hasil Pencarian:" << endl;
    for (const string& word : words) {
        if (searchWord(word)) {
            cout << word << ": Ada" << endl;
        } else {
            cout << word << ": Tidak Ada" << endl;
        }
    }
    return 0;
}
