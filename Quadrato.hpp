#include "Tetramino.hpp"

class Quadrato : public Tetramino {
    public:
    Quadrato(WINDOW *gameWin, Griglia *griglia);

    void Display();
    void Clear();
    void Update(int ch);
    void CheckCollision();

    bool CheckLeftEdge();
    bool CheckRightEdge();
};
