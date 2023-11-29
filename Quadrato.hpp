#include "Tetramino.hpp"

class Quadrato : public Tetramino {
    public:
    Quadrato(WINDOW *gameWin, Griglia *griglia);
    Quadrato();

    void Display();
    void Clear();
    void Update(int ch);
    void MoveDown();
    void CheckCollision();

    bool CheckLeftEdge();
    bool CheckRightEdge();
    bool isGameOver();
};
