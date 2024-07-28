namespace tic_tac_toe {
    class PIECE {
        private:
            char __piece;
        public:
            PIECE();
            PIECE(const char& type);
            char getpiece() const;
    };
}