#include "Tetramino.hpp"

class Linea : public Tetramino {
    public:

    bool isRotated = false;

    Linea(WINDOW *gameWin, Griglia *griglia);

    void Display();
    void Clear();
    void Update(int ch);
    void CheckCollision();


    bool CheckLeftEdge();
    bool CheckRightEdge();
    bool cantRotate();

    void Rotate();
};