namespace RB{
    class Rainbow{
        public:
            Rainbow(char one,char two,char three,char four,char five,char six,char seven);
            Rainbow(int one,int two,int three,int four,int five,int six,int seven);
            void getRainbowColorByName(char name);
            void outputRainbowColor();
        private:
            char current;
            char name[7];


    };
}