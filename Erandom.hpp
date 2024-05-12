#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/SoundSource.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Clipboard.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <Erandom_cortesia.hpp> //aqui tem a váriavel data contendo o hex/bin da fonte arial black e o icone padrão
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
//
//Esse hpp é o Erandom.hpp
//
//this Hpp is in someparts portuguese-brazil and others in english-EUA
//
//O significado dos namespace e a lib em si começar com E é porcausa do meu nome que é Ebert,ai peguei minha inicial + o nome
//
//Pode gerar bugs caso não saiba usar a lib corretamente!
//
//LICENSE/LICENÇA : https://www.apache.org/licenses/LICENSE-2.0.txt
//
//Embreve lançarei varias funções relacionadas ao SFML e melhoramento de algumas funções deprecárias!
//
//Anotações:
//template<typename tipo, typename tipo2>
//inline typename minhafuncao<tipo, tipo2>

#define VERSION_ERANDOM_HPP "Erandom Version: 1.0.6.9\nMinimu Version C++: 13\nOriginal Author: Ebert Silva de Assis\n"
#define PI_ERANDOM 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679 //PI 100 first digits
#define ERESET std::cout << "\033[0m" //All of theses need ASCII to work
#define EBLACK std::cout << "\033[30m"
#define ERED std::cout << "\033[31m"
#define EGREEN std::cout << "\033[32m"
#define EYELLOW std::cout << "\033[33m"
#define EBLUE std::cout << "\033[34m"
#define EMAGENTA std::cout << "\033[35m"
#define ECYAN std::cout << "\033[36m"
#define EWHITE std::cout << "\033[37m"
std::string Erandom_Version() {
    return VERSION_ERANDOM_HPP;
}
namespace Erandom {
    template<typename T>
    T randomChoice(const std::vector<T>& vec) {
        if (vec.empty()) {
            throw std::invalid_argument("Vector must not be empty");
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, vec.size() - 1);
        return vec[dist(gen)];
    }
    int randint(int min, int max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(min, max);
        return dist(gen);
    }
    template<typename T>
    T genericRandint(T min, T max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(min, max);
        return dist(gen);
    }
    std::string random_uuid(const std::string& lista, std::size_t length) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, lista.size() - 1);

        std::string result;
        for (std::size_t i = 0; i < length; ++i) {
            result += lista[dis(gen)];
        }
        return result;
    }
}
namespace Eutils {
    bool haSTR(std::string str2, std::string substr) { //verifica se tem uma substring em uma string e retorna um valor booleano
        std::string str = str2;
        std::string sub = substr;

        size_t pos = str.find(sub);

        if (pos != std::string::npos) {
            return true;
        } else {
            return false;
        }
        }

        bool isFloat(const std::string &s) {
        std::istringstream iss(s);
        float f;
        iss >> std::noskipws >>
            f; // Evita ignorar espaços em branco antes e depois do número
        return iss.eof() && !iss.fail(); // Verifica se a conversão foi bem-sucedida e
                                        // se não há mais caracteres para ler
        }

        bool findInVector(const std::vector<std::string>& vetor, const std::string& Procurado) {
            auto it = std::find(vetor.begin(), vetor.end(), Procurado);
            return it != vetor.end();
        }

        bool hasElementInVector(const std::vector<std::string>& lista, int indiceProcurado) {
            // Verifica se o índice está dentro do intervalo válido para o vetor
            return (indiceProcurado <= lista.size());
        }

    std::vector<std::string> split(std::string texto, char delimiter) {
        std::istringstream iss(texto);
        std::vector<std::string> partes;
        std::string parte;
        while (std::getline(iss, parte, delimiter)) {
            partes.push_back(parte);
        }
        return partes;
    }
    std::string Parser(std::string Text, std::string ToParse, int afterIndex = 0) {
        std::vector<std::string> res;
        res.push_back(Text);
        for (char& toRMV : ToParse) {
            res = Eutils::split(res[0], toRMV);
        }
        return res[afterIndex];
    }
    unsigned int notnegative(int value, int to_remove) {
        value -= to_remove;
        if (value < 0) {
            return 0;
        }
        return value;
    }

    template<typename T>
    T enumToValue(T item_enum) {
        return static_cast<T>(item_enum);
    }
    std::string ErroManager(std::map<int, std::string> lista_De_erros, int Error) { //Esta função é útil para mapas contendo hexadecimais de erros,e como conteudo,o significado e causa provavel do erro!
        if (lista_De_erros.find(Error) != lista_De_erros.end()) {
            return lista_De_erros[Error];
        }
        else {
            return "null";
        }
    }
    template<typename T>
    T GenericMapFinder(std::map<T, T> mapa, T item_a_se_pesquisar) {
        if (mapa.find(item_a_se_pesquisar) != mapa.end()) {
            return mapa[item_a_se_pesquisar];
        }
        else {
            return "null";
        }
    }


}
namespace Etweens {
    struct vector2f {
        double x;
        double y;
    };
    struct vector2int {
        int x;
        int y;
    };
    std::vector<vector2int> Vectortween(vector2int thisvector, vector2int toReachVector) {
        std::vector<vector2int> conjuto;
        bool running = true;
        while (running) {
            if (thisvector.x < toReachVector.x) {
                thisvector.x++;
            }
            if (thisvector.y < toReachVector.y) {
                thisvector.y++;
            }
            conjuto.push_back({thisvector.x, thisvector.y});
            if (thisvector.x == toReachVector.x && thisvector.y == toReachVector.y) {
                running = false;
            }
        }
        return conjuto;
    }
    std::vector<vector2f> TweenOrbit(double centerX, double centerY, double radius, double smoothness) {
        const double PI = PI_ERANDOM;
        std::vector<vector2f> orbitPoints;
        int numPoints = static_cast<int>(2 * PI * radius / smoothness);

        for (int i = 0; i < numPoints; ++i) {
            double angle = 2 * PI * i / numPoints;
            double x = centerX + radius * std::cos(angle);
            double y = centerY + radius * std::sin(angle);

            orbitPoints.push_back({x, y});
        }

        return orbitPoints;
    }
}
namespace Emath {
    float notable_angles_1 = 90.0f;
    float notable_angles_2 = 30.0f;
    float notable_angles_3 = 45.0f;
    float notable_angles_4 = 60.0f;
    float Seno(float Angulo_grau) {
        float radius = Angulo_grau * (PI_ERANDOM / 180);
        return radius - (std::pow(radius, 3)) / 6 + (std::pow(radius, 5) / 120);
    }
    float Cosseno(float Angulo_grau) {
        float radius = Angulo_grau * (PI_ERANDOM / 180);
        return 1.0 - (std::pow(radius, 2)) / 2 + (std::pow(radius, 4) / 24);
    }
    float Tangente(float Angulo_grau1, float Angulo_grau2) {
    // Converter ângulos para radianos
    float radius1 = Angulo_grau1 * (PI_ERANDOM / 180);
    float radius2 = Angulo_grau2 * (PI_ERANDOM / 180);
    
    // Calcular a tangente dos ângulos
    float tan1 = std::tan(radius1);
    float tan2 = std::tan(radius2);
    return tan1, tan2;
}

    float PointDistance(float x1, float y1, float x2, float y2) {//caso essa não funcione use calculateDistance
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }
    Etweens::vector2f CalculatePosition(float X, float Y, float SizeX, float SizeY) {
        return {(X - SizeX), (Y - SizeY)};
    }
    bool CollisionCircle(float x1, float y1, float raio1, float x2, float y2, float raio2) {
        float distancia = PointDistance(x1, y1, x2, y2);
        return distancia <= raio1 + raio2;
    }
    double calculateDistance(const Etweens::vector2int& point1, const Etweens::vector2int& point2) { //caso essa não funcione use PointDistance
        int x_diff = point2.x - point1.x;
        int y_diff = point2.y - point1.y;
        return std::sqrt(x_diff * x_diff + y_diff * y_diff);
    }
    int Double2int(double numero) {
        return static_cast<int>(std::round(numero));
    }
    //Apartir daqui são contas matematicas espaciais e de ambiente
    /* Function to linearly interpolate between a0 and a1
    * Weight w should be in the range [0.0, 1.0]
    */
    float interpolate(float a0, float a1, float w) {
        /* // You may want clamping by inserting:
        * if (0.0 > w) return a0;
        * if (1.0 < w) return a1;
        */
        return (a1 - a0) * w + a0;
        /* // Use this cubic interpolation [[Smoothstep]] instead, for a smooth appearance:
        * return (a1 - a0) * (3.0 - w * 2.0) * w * w + a0;
        *
        * // Use [[Smootherstep]] for an even smoother result with a second derivative equal to zero on boundaries:
        * return (a1 - a0) * ((w * (w * 6.0 - 15.0) + 10.0) * w * w * w) + a0;
        */
    }

    typedef struct {
        float x, y;
    } vector2;

    /* Create pseudorandom direction vector
    */
    vector2 randomGradient(int ix, int iy) {
        // No precomputed gradients mean this works for any number of grid coordinates
        const unsigned w = 8 * sizeof(unsigned);
        const unsigned s = w / 2; // rotation width
        unsigned a = ix, b = iy;
        a *= 3284157443; b ^= a << s | a >> w-s;
        b *= 1911520717; a ^= b << s | b >> w-s;
        a *= 2048419325;
        float random = a * (3.14159265 / ~(~0u >> 1)); // in [0, 2*Pi]
        vector2 v;
        v.x = cos(random); v.y = sin(random);
        return v;
    }

    // Computes the dot product of the distance and gradient vectors.
    float dotGridGradient(int ix, int iy, float x, float y) {
        // Get gradient from integer coordinates
        vector2 gradient = randomGradient(ix, iy);

        // Compute the distance vector
        float dx = x - (float)ix;
        float dy = y - (float)iy;

        // Compute the dot-product
        return (dx*gradient.x + dy*gradient.y);
    }

    // Compute Perlin noise at coordinates x, y
    float Enoise(float x, float y) {
        // Determine grid cell coordinates
        int x0 = (int)floor(x);
        int x1 = x0 + 1;
        int y0 = (int)floor(y);
        int y1 = y0 + 1;

        // Determine interpolation weights
        // Could also use higher order polynomial/s-curve here
        float sx = x - (float)x0;
        float sy = y - (float)y0;

        // Interpolate between grid point gradients
        float n0, n1, ix0, ix1, value;

        n0 = dotGridGradient(x0, y0, x, y);
        n1 = dotGridGradient(x1, y0, x, y);
        ix0 = interpolate(n0, n1, sx);

        n0 = dotGridGradient(x0, y1, x, y);
        n1 = dotGridGradient(x1, y1, x, y);
        ix1 = interpolate(n0, n1, sx);

        value = interpolate(ix0, ix1, sy);
        return value; // Will return in range -1 to 1. To make it in range 0 to 1, multiply by 0.5 and add 0.5
    }
    float ForceGrav(float mass1, float mass2, float dist) {
        return ((mass1 * mass2) / dist);
    }

    typedef std::map<float, int> dump;
    struct Matriz {
        std::vector<dump> X;
        std::vector<dump> Y;
    };
    /*
    Matriz BigBangParticules(float SizeX, float SizeY, int CPPSChance Para Pontos Surgirem) 2D apenas {
        Matriz matriz;
        for (int x = 0; x < SizeX; x++) {
            for (int y = 0; y < SizeY; y++) {
                int sorte = Emath::Double2int(Erandom::randint(0, (CPPS * 1.5)));
                if (sorte <= CPPS) {
                    dump obj1;
                    dump obj2;
                    obj1 = {x, Erandom::randint(0, 100)};
                    obj2 = {y, Erandom::randint(0, 100)};
                    matriz.X = obj1;
                    matriz.Y = obj2;
                }
            }
        }
        return matriz;
    }
    */
}

namespace Ecurses {
    class Ncurses {
        public:
        std::vector<std::string> OldTxt;
        int linesToClean = 900;
        //char fill = '■';
        int Xnow = 0;
        int Ynow = 0;
        void clean() {
            for (int i = 0; i < linesToClean; i++) {
                std::cout << '\n';
            }
        }
        void setCursorPos(int ColunX, int ColunY) {
            Xnow = ColunX;
            Ynow = ColunY;
        }
        template<typename T>
        void print(T Fmt, bool Save = true) {
            for (int i = 0; i < Ynow; i++) {
                std::cout << '\n';
            }
            for (int i = 0; i < Xnow; i++) {
                std::cout << ' ';
            }
            std::cout << Fmt;
            if (Save) {
                OldTxt.push_back(Fmt);
            }
        }
    };
}

namespace Esfml /*Após meses,finalmente decide fazelo*/ {
    struct label { 
        sf::RectangleShape hitbox;  //Hitbox, após para detectar se foi clicada,use um bool e após isso o mouseClickedRect
        sf::Text texto;             //Texto
        sf::RectangleShape fachada; //Não é necessário caso não queira
        bool is_focused;            //útil para detectar inputs,use isto quando for fazer um input,se true,todo texto mande para 'texto'
        
    }; //hitbox precisa ser igual ou maior que texto para melhor funcionamento
    bool mouseClickedRect(sf::RectangleShape rect, sf::Vector2i mouse) {
        return rect.getGlobalBounds().contains(mouse.x, mouse.y);
    }
}
class EbetterSfml {
public:
    sf::Clock deltaTime;
    sf::Clipboard clipboard;
    sf::Music audio;
    float Volume = 50;
    sf::RenderWindow window; // Membro para armazenar a janela
    enum Errors {
        None = 0x0,
        File_not_found = 0x1,
        Unknown_err = 0x2,
        Audio_err = 0x3,
        Bad_Action = 0x4,
    };
    /// @note Em brve mais adição de possiveis ações
    enum Actions {
        Nothing,
        Load,
        Play,
        Stop,
        Pause,
        VolChange
    };
    // Construtor para inicializar a janela
    EbetterSfml() : window(sf::VideoMode(800, 600), "Janela", sf::Style::Default, sf::ContextSettings(0, 0, 25)) {
        sf::Image iconDefault;
        iconDefault.loadFromMemory(defaultIcon.data(), defaultIcon.size());
        window.setIcon(iconDefault.getSize().x, iconDefault.getSize().y, iconDefault.getPixelsPtr());
    }

    // Função para iniciar o programa
    void init() {
        start();
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                on_event(event);
            }
            update();
        }
    }

    // Função para iniciar o programa
    virtual void start() {
        EYELLOW;
        std::cout << "Programa iniciado!\n";
        EWHITE;
    }

    // Função para atualizar a lógica do jogo
    virtual void update() {
        window.clear();
        window.display();
    }

    // Função para lidar com eventos
    virtual void on_event(sf::Event event) {
        if (event.type == event.Closed) {
            window.close();
        }
    }

    // Função para manipular áudio
    Errors music(std::string audioName, Actions action) {
        if (action == Actions::Play) {
            audio.setVolume(Volume);
            audio.play();
        } else if (action == Actions::Pause) {
            audio.pause();
        } else if (action == Actions::Load) {
            if (!audio.openFromFile(audioName)) {
                return Errors::File_not_found;
            }
        } else if (action == Actions::Stop) {
            audio.stop();
        } else if (action == Actions::VolChange) {
            audio.setVolume(Volume);
        } else {
            return Errors::Bad_Action;
        }
        return Errors::None;
    }
};
