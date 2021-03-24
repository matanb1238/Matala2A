#include "Direction.hpp"
#include <vector>
#include <string>
#define SIZE 10

using namespace std;

namespace ariel{
 
    class Board{
        private:
            uint rows;
            uint cols;
            vector<vector<char>> board;
        public:
        Board(){
            board = vector<vector<char>>(SIZE , vector<char> (SIZE, '_'));
            rows = SIZE;
            cols = SIZE;
        }
        uint get_rows(){return rows;};
        uint get_cols(){return cols;};
        void post(u_int row, u_int col, Direction d, std::string str);
        static string read(u_int row, u_int col, Direction d, u_int length);
        void show();
    };
}