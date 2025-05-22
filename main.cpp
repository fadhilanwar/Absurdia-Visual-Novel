#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

struct Scene {
    string npcLine;
    string mcPrompt;
    string choiceText;
    vector<pair<char, Scene*>> choices;
};

// Stack untuk rewind
stack<Scene*> history;

// Menampilkan border panel
// void drawPanel(const string& title, const string& text) {
//     size_t maxLen = max(title.size(), text.size());

//     cout << "+" << string(maxLen, '-') << "+\n";
//     cout << "| " << title << string(maxLen - title.size(), ' ') << "|\n";
//     cout << "+" << string(maxLen, '-') << "+\n";
//     cout << "| " << text << string(maxLen - text.size(), ' ') << "|\n";
//     cout << "+" << string(maxLen, '-') << "+\n";
// }


void play(Scene* current) {
    while (true) {
        // drawPanel("NPC", current->npcLine);
        // drawPanel("MC", current->mcPrompt);

        cout << "[NPC]: " << current->npcLine << endl;
        cout << "[MC]: " << current->mcPrompt << endl;

        history.push(current); // simpan langkah

        if (current->choices.empty()) {
            cout << "\n[=== Cerita Selesai ===]\n";
            break;
        }

        cout << "\nPilihan:\n";
        for (auto& choice : current->choices) {
            cout << choice.first << ". " << choice.second->choiceText << "\n";
        }
        cout << "0. Undo langkah\n>> Pilih: ";

        string input;
        cin >> input;

       if (input == "0") {
            if (!history.empty()) history.pop(); // buang current
            if (!history.empty()) {
                current = history.top(); history.pop(); // balik 1 langkah
            } else {
                cout << "Tidak bisa undo lebih jauh!\n";
            }
        } else if (input.size() == 1) {
            char pick = toupper(input[0]);
            bool found = false;
            for (auto& choice : current->choices) {
                if (choice.first == pick) {
                    current = choice.second;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Pilihan tidak valid.\n";
                history.pop(); // rollback push
            }
        } else {
            cout << "Input tidak dikenali.\n";
            history.pop();
        }
    }
}

int main() {
    Scene* root = new Scene{
    "Teman-teman mulai berhamburan mencari tempat berteduh.",
    "Hujan deras mengguyur halaman. Apa yang akan kamu lakukan?",
    "", {}
};

// Pilihan level 1
Scene* bantuTeman = new Scene{
    "Temanmu kesulitan membawa buku-bukunya sambil lari ke kelas.",
    "Tentukan pil-ihanmu.",
    "A. Membantu teman membawa buku", {}
};
Scene* keKantin = new Scene{
    "Kamu memutuskan menuju kantin meskipun hujan deras.",
    "Tentukan pilihanmu.",
    "B. Pergi ke kantin", {}
};
Scene* diamDiKoridor = new Scene{
    "Kamu berdiri di koridor menunggu hujan reda.",
    "Tentukan pilihanmu.",
    "C. Menunggu di koridor", {}
};

root->choices.push_back({'A', bantuTeman});
root->choices.push_back({'B', keKantin});
root->choices.push_back({'C', diamDiKoridor});

// Cabang bantuTeman (A/B)
Scene* dekatTeman = new Scene{
    "Dia tersAenyum, 'Terima kasih ya!' Kalian mulai sering ngobrol.",
    "Lanjutkan perjalananmu...",
    "A. Membantu", {}
};
Scene* dianggapAneh = new Scene{
    "Dia terlihat canggung dan buru-buru pergi tanpa berkata apa-apa.",
    "Lanjutkan perjalananmu...",
    "B. Tidak berkata apa-apa setelah membantu", {}
};

bantuTeman->choices.push_back({'A', dekatTeman});
bantuTeman->choices.push_back({'B', dianggapAneh});

// Cabang keKantin (A/B)
Scene* temanBaru = new Scene{
    "Kamu bertemu siswa dari kelas lain yang ramah.",
    "Lanjutkan perjalananmu...",
    "A. Bertemu teman baru", {}
};
Scene* dimarahiPenjaga = new Scene{
    "Penjaga kantin berteriak, 'Basah-basahan di sini! Keluar!'.",
    "Lanjutkan perjalananmu...",
    "B. Kena semprot", {}
};

keKantin->choices.push_back({'A', temanBaru});
keKantin->choices.push_back({'B', dimarahiPenjaga});

// Cabang diamDiKoridor → guru ngobrol (A/B) dan siswa bertengkar (A/B)
Scene* ngobrolGuru = new Scene{
    "Guru datang dan berkata, 'Kamu punya waktu sebentar?'.",
    "Apa yang kamu lakukan?",
    "A. Diajak ngobrol guru", {}
};
Scene* lihatBertengkar = new Scene{
    "Kamu melihat dua siswa bertengkar di ujung koridor.",
    "Apa yang kamu lakukan?",
    "B. Melihat siswa bertengkar", {}
};

diamDiKoridor->choices.push_back({'A', ngobrolGuru});
diamDiKoridor->choices.push_back({'B', lihatBertengkar});

// Cabang ngobrolGuru (A/B)
Scene* dapatNasihat = new Scene{
    "Guru memberikan nasihat yang membuka pikiranmu.",
    "Lanjutkan perjalananmu...",
    "A. Mendengarkan nasihat", {}
};
Scene* merasaBosan = new Scene{
    "Guru bercerita terlalu lama. Kamu merasa mengantuk.",
    "Lanjutkan perjalananmu...",
    "B. Bosan", {}
};

ngobrolGuru->choices.push_back({'A', dapatNasihat});
ngobrolGuru->choices.push_back({'B', merasaBosan});

// Cabang lihatBertengkar (A/B)
Scene* melerai = new Scene{
    "Kamu mencoba melerai mereka dan berhasil.",
    "Lanjutkan perjalananmu...",
    "A. Meleraikan pertengkaran", {}
};
Scene* abaikan = new Scene{
    "Kamu memilih mengabaikannya dan pergi.",
    "Lanjutkan perjalananmu...",
    "B. Mengabaikan", {}
};

lihatBertengkar->choices.push_back({'A', melerai});
lihatBertengkar->choices.push_back({'B', abaikan});


    play(root);
    return 0;
}
