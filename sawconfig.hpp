#ifndef SAWCONFIG_HPP_INCLUDED
#define SAWCONFIG_HPP_INCLUDED

class SawConfig {
    protected: int edgeQuantion, doubleThickQuantion, sawThick;

    public: SawConfig();

    public: int getEdgeQuantion();
    public: int getDoubleThickQuantion();
    public: int getSawThick();

    public: SawConfig * setEdgeQuantion(int value);
    public: SawConfig * setDoubleThickQuantion(int value);
    public: SawConfig * setSawThick(int value);
};


#endif // SAWCONFIG_HPP_INCLUDED
