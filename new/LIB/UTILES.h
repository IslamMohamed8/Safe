#ifndef UTILES_H_
#define UTILES_H_

#define SETBIT(REG , BITno)              REG |= (1 << BITno)
#define CLRBIT(REG , BITno)              REG &= ~(1 << BITno)
#define GETBIT(REG , BITno)              (REG >> BITno) & (1)
#define ASSIGNBIT(REG , BITno , VALUE)   REG = (REG & ~(1 << BITno))|(VALUE << BITno)
#define TOGGLEBIT(REG , BITno)           REG ^= (1 << BITno)

#define SETPORT(REG)                     REG |= 0xFF
#define CLRPORT(REG)                     REG &= 0x00
#define GETPORT(REG)                     REG & 0xFF
#define ASSIGNPORT(REG , VALUE)          REG = ((REG & 0x00)|VALUE)
#define TOGGLEPORT(REG)                  REG ^= 0xFF

//shift right and shift left
#define Rotate_Right(reg,no)              reg=(reg<<(8*sizeof(reg)-(no)))|(reg>>(no))
#define Rotate_Left(reg,no)               reg=(reg<<(no))|(reg>>(8*sizeof(reg)-(no)))

#endif /* UTILES_H_ */
