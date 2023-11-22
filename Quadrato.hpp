#include "Tetramino.hpp"

class Quadrato : public Tetramino {
    public:
    Quadrato(WINDOW *gameWin);
    Quadrato();

    void Display();
    void Clear();
    void Update(int ch);
    void MoveDown();
    void CheckBottomEdge();
    void CheckLateralEdges();
};
