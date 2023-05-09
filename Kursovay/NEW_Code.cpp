#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>

using namespace sf;

class TagGame {
public:
    TagGame() {
        srand(time(0));
        window.create(VideoMode(512, 512), "Tag game!");
        window.setFramerateLimit(60);
        texture.loadFromFile("C:/Users/Maibenben/Desktop/Paint/Pro/1.png");
        int a = rand() % 5 + 1;
        switch (a) {
        case 1:
            texture.loadFromFile("C:/Users/Maibenben/Desktop/Paint/Pro/1.png");
            break;
        case 2:
            texture.loadFromFile("C:/Users/Maibenben/Desktop/Paint/Pro/2.png");
            break;
        case 3:
            texture.loadFromFile("C:/Users/Maibenben/Desktop/Paint/Pro/3.png");
            break;
        case 4:
            texture.loadFromFile("C:/Users/Maibenben/Desktop/Paint/Pro/4.png");
            break;
        case 5:
            texture.loadFromFile("C:/Users/Maibenben/Desktop/Paint/Pro/5.png");
            break;
        }
        sprite = new Sprite[17];
        int w = 128;
        int grid[6][6] = { 0 };
        int n = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                n++;
                sprite[n].setTexture(texture);
                sprite[n].setTextureRect(IntRect(i * w, j * w, w, w));
                grid[i + 1][j + 1] = n;
            }
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close();
                if (event.type == Event::MouseButtonPressed)
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        Vector2i pos = Mouse::getPosition(window);
                        int x = pos.x / w + 1;
                        int y = pos.y / w + 1;
                        int dx = 0;
                        int dy = 0;
                        int b;
                        if (a != 2 && a != 5)
                            b = 16;
                        else if (a == 2 || a == 5)
                            b = 4;
                        if (grid[x + 1][y] == b) {
                            dx = 1;
                            dy = 0;
                        }
                        if (grid[x - 1][y] == b) {
                            dx = -1;
                            dy = 0;
                        }
                        if (grid[x][y - 1] == b) {
                            dx = 0;
                            dy = -1;
                        }
                        if (grid[x][y + 1] == b) {
                            dx = 0;
                            dy = 1;
                        }
                        n = grid[x][y];
                        grid[x][y] = b;
                        grid[x + dx][y + dy] = n;
                        sprite[b].move(-dx * w, -dy * w);
                        float speed = 16;
                        for (int i = 0; i < w; i += speed) {
                            sprite[n].move(speed * dx, speed * dy);
                            window.draw(sprite[b]);
                            window.draw(sprite[n]);
                            window.display();
                        }
                    }
            }
            window.clear(Color::White);
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++) {
                    n = grid[i + 1][j + 1];
                    sprite[n].setPosition(i * w, j * w);
                    window.draw(sprite[n]);
                }
            window.display();
        }
    }
private:
    RenderWindow window;
    Texture texture;
    Sprite* sprite;
};

int main() {
    TagGame game;
    return 0;
}
