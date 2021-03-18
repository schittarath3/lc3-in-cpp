#include <cstdint>
using std::int16_t;

class LC3 {
    public:
        //constructor
        LC3();                          

        //data storage
        int16_t mem[INT16_MAX];     //LC3 Memory
                                        //mem[x0000:x00FF]  Trap Vector Table
                                        //mem[x0100:0x01FF] Interreupt Vector Table
                                        //mem[x0200:x2FFF]  Supervisor Stack
                                        //mem[x3000:xFDFF]  User Space
                                        //mem[xFE00:xFFFF]  Device Register Addresses
                  
        int16_t reg[13];            //LC3 Registers
                                        //REGFILE[0:7], 
                                        //PC[8], 
                                        //IR[9], 
                                        //Condition Codes: 
                                            //N[10], 
                                            //Z[11], 
                                            //P[12]
        
        //LC3 Methods
        int16_t addrADD;
        int16_t sext();

        //LC3 instructions

        //ALU operations
        void ADD0(int16_t DR, int16_t SR1, int16_t SR2);
        void ADD1(int16_t DR, int16_t SR1, int16_t imm5);
        void AND0(int16_t DR, int16_t SR1, int16_t SR2);
        void AND1(int16_t DR, int16_t SR1, int16_t imm5);
        void NOT(int16_t DR, int16_t SR);

        //Conditional branching
        void BR(bool n, bool z, bool p, int16_t PCoffset9);
        void JMP(int16_t BaseR);

        //Subroutine control
        void JSR(int16_t PCoffset11);
        void JSRR(int16_t BaseR);
        void RET();

        //Register loading
        void LD(int16_t DR, int16_t PCoffset9);
        void LDI(int16_t DR, int16_t PCoffset9);
        void LDR(int16_t DR, int16_t BaseR, int16_t offset6);
        void LEA(int16_t DR, int16_t offset9);

        //Memory loading
        void ST(int16_t SR, int16_t PCoffset9);
        void STI(int16_t SR, int16_t PCoffset9);
        void STR(int16_t SR, int16_t BaseR, int16_t offset6);

        //Supervisor subroutines
        void TRAP(int16_t trapvect8);

        //non-LC3-specific methods
        //add subroutines that would not be done by regular instructions
        //Example:
        //void createMatrix();
        //void matrixADD();

    private:
        void updateCC();        //Should only be called during ALU, and Load operations
};


//Methods assume that all inputs are correctly parsed

//*ADD COMMENTS FOR EACH METHOD**

void LC3::ADD0(int16_t DR, int16_t SR1, int16_t SR2) {
    LC3::reg[DR] = LC3::reg[SR1] + LC3::reg[SR2];
}

//add sign extension for imm5
void LC3::ADD1(int16_t DR, int16_t SR1, int16_t imm5) {
    LC3::reg[DR] = LC3::reg[SR1] + imm5;
}

void LC3::AND0(int16_t DR, int16_t SR1, int16_t SR2) {
    LC3::reg[DR] = LC3::reg[SR1] & LC3::reg[SR2];
}

//add sign extension for imm5
void LC3::AND1(int16_t DR, int16_t SR1, int16_t imm5) {
    LC3::reg[DR] = LC3::reg[SR1] & imm5;
}
void LC3::NOT(int16_t DR, int16_t SR) {
    LC3::reg[DR] = ~LC3::reg[SR];
}
