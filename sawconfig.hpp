#ifndef SAWCONFIG_HPP_INCLUDED
#define SAWCONFIG_HPP_INCLUDED

class SawConfig {
    protected: static bool loaded;
    protected: static int edgeQuantion, doubleThickQuantion, sawThick;

    public: static void loadParams();
    public: static int getEdgeQuantion();
    public: static int getDoubleThickQuantion();
    public: static int getSawThick();

    public: static void setEdgeQuantion(int value);
    public: static void setDoubleThickQuantion(int value);
    public: static void setSawThick(int value);
};


#endif // SAWCONFIG_HPP_INCLUDED
