/*
 * Common MUSB core registers definitions
 */

#ifndef _MUSB_REGS_H_
#define _MUSB_REGS_H_

#include <usb/hcd_common.h>


/*===========================================================================*
 *    MUSB core register offsets                                             *
 *===========================================================================*/
#define MUSB_REG_FADDR				0x00u
#define MUSB_REG_POWER				0x01u
#define MUSB_REG_INTRTX				0x02u
#define MUSB_REG_INTRRX				0x04u
#define MUSB_REG_INTRTXE			0x06u
#define MUSB_REG_INTRRXE			0x08u
#define MUSB_REG_INTRUSB			0x0Au
#define MUSB_REG_INTRUSBE			0x0Bu
#define MUSB_REG_FRAME				0x0Cu
#define MUSB_REG_INDEX				0x0Eu
#define MUSB_REG_TESTMODE			0x0Fu

/* Proxy registers for endpoint configuration,
 * that correspond to specific endpoint's register space
 * selected with MUSB_REG_INDEX */
#define MUSB_REG_TXMAXP				0x10u
#define MUSB_REG_PERI_CSR0			0x12u
#define MUSB_REG_HOST_CSR0				MUSB_REG_PERI_CSR0
#define MUSB_REG_PERI_TXCSR				MUSB_REG_PERI_CSR0
#define MUSB_REG_HOST_TXCSR				MUSB_REG_PERI_CSR0
#define MUSB_REG_RXMAXP				0x14u
#define MUSB_REG_PERI_RXCSR			0x16u
#define MUSB_REG_HOST_RXCSR				MUSB_REG_PERI_RXCSR
#define MUSB_REG_COUNT0				0x18u
#define MUSB_REG_RXCOUNT				MUSB_REG_COUNT0
#define MUSB_REG_HOST_TYPE0			0x1Au
#define MUSB_REG_HOST_TXTYPE				MUSB_REG_HOST_TYPE0
#define MUSB_REG_HOST_NAKLIMIT0			0x1Bu
#define MUSB_REG_HOST_TXINTERVAL			MUSB_REG_HOST_NAKLIMIT0
#define MUSB_REG_HOST_RXTYPE			0x1Cu
#define MUSB_REG_HOST_RXINTERVAL		0x1Du

#define MUSB_REG_FIFO0				0x20u
#define MUSB_REG_FIFO1				0x24u
#define MUSB_REG_FIFO2				0x28u
#define MUSB_REG_FIFO3				0x2Cu
#define MUSB_REG_FIFO4				0x30u
#define MUSB_REG_FIFO_LEN			0x04u

#define MUSB_REG_DEVCTL				0x60u
#define MUSB_REG_TXFIFOSZ			0x62u
#define MUSB_REG_RXFIFOSZ			0x63u
#define MUSB_REG_TXFIFOADDR			0x64u
#define MUSB_REG_RXFIFOADDR			0x66u

#define MUSB_REG_EP_CONFIG_BASE			0x80u
#define MUSB_REG_TXFUNCADDR			0x00u
#define MUSB_REG_TXHUBADDR			0x02u
#define MUSB_REG_TXHUBPORT			0x03u
#define MUSB_REG_RXFUNCADDR			0x04u
#define MUSB_REG_RXHUBADDR			0x06u
#define MUSB_REG_RXHUBPORT			0x07u
#define MUSB_REG_EP_CONFIG_LEN			0x08u
#define MUSB_REG_CONFIG(ep,reg)			\
	(MUSB_REG_EP_CONFIG_BASE + (MUSB_REG_EP_CONFIG_LEN * (ep)) + (reg))


/*===========================================================================*
 *    MUSB core register values                                              *
 *===========================================================================*/
/* POWER */
#define MUSB_VAL_POWER_ENSUSPM			HCD_BIT(0)
#define MUSB_VAL_POWER_SUSPENDM			HCD_BIT(1)
#define MUSB_VAL_POWER_RESUME			HCD_BIT(2)
#define MUSB_VAL_POWER_RESET			HCD_BIT(3)
#define MUSB_VAL_POWER_HSMODE			HCD_BIT(4)
#define MUSB_VAL_POWER_HSEN			HCD_BIT(5)
#define MUSB_VAL_POWER_SOFTCONN			HCD_BIT(6)
#define MUSB_VAL_POWER_ISOUPDATE		HCD_BIT(7)

/* DEVCTL */
#define MUSB_VAL_DEVCTL_SESSION			HCD_BIT(0)
#define MUSB_VAL_DEVCTL_HOSTREQ			HCD_BIT(1)
#define MUSB_VAL_DEVCTL_HOSTMODE		HCD_BIT(2)
#define MUSB_VAL_DEVCTL_VBUS_1			HCD_BIT(3)
#define MUSB_VAL_DEVCTL_VBUS_2			HCD_BIT(4)
#define MUSB_VAL_DEVCTL_VBUS_3			(HCD_BIT(3) | HCD_BIT(4))
#define MUSB_VAL_DEVCTL_LSDEV			HCD_BIT(5)
#define MUSB_VAL_DEVCTL_FSDEV			HCD_BIT(6)
#define MUSB_VAL_DEVCTL_BDEVICE			HCD_BIT(7)

/* INTRUSBE */
#define MUSB_VAL_INTRUSBE_SUSPEND		HCD_BIT(0)
#define MUSB_VAL_INTRUSBE_RESUME		HCD_BIT(1)
#define MUSB_VAL_INTRUSBE_RESET_BABBLE		HCD_BIT(2)
#define MUSB_VAL_INTRUSBE_SOF			HCD_BIT(3)
#define MUSB_VAL_INTRUSBE_CONN			HCD_BIT(4)
#define MUSB_VAL_INTRUSBE_DISCON		HCD_BIT(5)
#define MUSB_VAL_INTRUSBE_SESSREQ		HCD_BIT(6)
#define MUSB_VAL_INTRUSBE_VBUSERR		HCD_BIT(7)
#define MUSB_VAL_INTRUSBE_NONE			0x00u

/* HOST_TYPE0 */
#define MUSB_VAL_HOST_TYPE0_MASK		(HCD_BIT(6) | HCD_BIT(7))
#define MUSB_VAL_HOST_TYPE0_HIGH_SPEED		HCD_BIT(6)
#define MUSB_VAL_HOST_TYPE0_FULL_SPEED		HCD_BIT(7)
#define MUSB_VAL_HOST_TYPE0_LOW_SPEED		(HCD_BIT(6) | HCD_BIT(7))

/* INTRTXE */
#define MUSB_VAL_INTRTXE_EP0			HCD_BIT(0)
#define MUSB_VAL_INTRTXE_EP1TX			HCD_BIT(1)
#define MUSB_VAL_INTRTXE_EP2TX			HCD_BIT(2)
#define MUSB_VAL_INTRTXE_EP3TX			HCD_BIT(3)
#define MUSB_VAL_INTRTXE_EP4TX			HCD_BIT(4)

/* HOST_CSR0 */
#define MUSB_VAL_HOST_CSR0_RXPKTRDY		HCD_BIT(0)
#define MUSB_VAL_HOST_CSR0_TXPKTRDY		HCD_BIT(1)
#define MUSB_VAL_HOST_CSR0_RXSTALL		HCD_BIT(2)
#define MUSB_VAL_HOST_CSR0_SETUPPKT		HCD_BIT(3)
#define MUSB_VAL_HOST_CSR0_ERROR		HCD_BIT(4)
#define MUSB_VAL_HOST_CSR0_REQPKT		HCD_BIT(5)
#define MUSB_VAL_HOST_CSR0_STATUSPKT		HCD_BIT(6)
#define MUSB_VAL_HOST_CSR0_NAK_TIMEOUT		HCD_BIT(7)
#define MUSB_VAL_HOST_CSR0_FLUSHFIFO		HCD_BIT(8)

/* HOST_RXTYPE/HOST_TXTYPE */
#define MUSB_VAL_HOST_XXTYPE_SPEED_MASK		(HCD_BIT(6) | HCD_BIT(7))
#define MUSB_VAL_HOST_XXTYPE_HIGH_SPEED		HCD_BIT(6)
#define MUSB_VAL_HOST_XXTYPE_FULL_SPEED		HCD_BIT(7)
#define MUSB_VAL_HOST_XXTYPE_LOW_SPEED		(HCD_BIT(6) | HCD_BIT(7))
#define MUSB_VAL_HOST_XXTYPE_PROT_MASK		(HCD_BIT(4) | HCD_BIT(5))
#define MUSB_VAL_HOST_XXTYPE_ISOCHRONOUS	HCD_BIT(4)
#define MUSB_VAL_HOST_XXTYPE_BULK		HCD_BIT(5)
#define MUSB_VAL_HOST_XXTYPE_INTERRUPT		(HCD_BIT(4) | HCD_BIT(5))
#define MUSB_VAL_HOST_XXTYPE_RENDPN_MASK	(HCD_BIT(0) |		\
						 HCD_BIT(1) |		\
						 HCD_BIT(2) |		\
						 HCD_BIT(3))

/* HOST_RXINTERVAL/HOST_TXINTERVAL */
/* Default NAK limit for non-control transfer
 * When too big this may cause driver to wait for
 * quite long in case of NAK error */
#define MUSB_VAL_HOST_XXINTERVAL_DEFAULT	0x10u

/* HOST_RXCSR */
#define MUSB_VAL_HOST_RXCSR_RXPKTRDY		HCD_BIT(0)
#define MUSB_VAL_HOST_RXCSR_FIFOFULL		HCD_BIT(1)
#define MUSB_VAL_HOST_RXCSR_ERROR		HCD_BIT(2)
#define MUSB_VAL_HOST_RXCSR_NAKTIMEOUT		HCD_BIT(3)
#define MUSB_VAL_HOST_RXCSR_FLUSHFIFO		HCD_BIT(4)
#define MUSB_VAL_HOST_RXCSR_REQPKT		HCD_BIT(5)
#define MUSB_VAL_HOST_RXCSR_RXSTALL		HCD_BIT(6)
#define MUSB_VAL_HOST_RXCSR_CLRDATATOG		HCD_BIT(7)
#define MUSB_VAL_HOST_RXCSR_DATATOG		HCD_BIT(9)
#define MUSB_VAL_HOST_RXCSR_DATATOGWREN		HCD_BIT(10)
#define MUSB_VAL_HOST_RXCSR_DISNYET		HCD_BIT(12)
#define MUSB_VAL_HOST_RXCSR_DMAEN		HCD_BIT(13)

/* HOST_TXCSR */
#define MUSB_VAL_HOST_TXCSR_TXPKTRDY		HCD_BIT(0)
#define MUSB_VAL_HOST_TXCSR_FIFONOTEMPTY	HCD_BIT(1)
#define MUSB_VAL_HOST_TXCSR_ERROR		HCD_BIT(2)
#define MUSB_VAL_HOST_TXCSR_FLUSHFIFO		HCD_BIT(3)
#define MUSB_VAL_HOST_TXCSR_SETUPPKT		HCD_BIT(4)
#define MUSB_VAL_HOST_TXCSR_RXSTALL		HCD_BIT(5)
#define MUSB_VAL_HOST_TXCSR_CLRDATATOG		HCD_BIT(6)
#define MUSB_VAL_HOST_TXCSR_NAK_TIMEOUT		HCD_BIT(7)
#define MUSB_VAL_HOST_TXCSR_DATATOG		HCD_BIT(8)
#define MUSB_VAL_HOST_TXCSR_DATATOGWREN		HCD_BIT(9)
#define MUSB_VAL_HOST_TXCSR_DMAMODE		HCD_BIT(10)
#define MUSB_VAL_HOST_TXCSR_FRCDATATOG		HCD_BIT(11)
#define MUSB_VAL_HOST_TXCSR_DMAEN		HCD_BIT(12)
#define MUSB_VAL_HOST_TXCSR_MODE		HCD_BIT(13)
#define MUSB_VAL_HOST_TXCSR_ISO			HCD_BIT(14)
#define MUSB_VAL_HOST_TXCSR_AUTOSET		HCD_BIT(15)

/* RXFIFOADDR/TXFIFOADDR */
#define MUSB_VAL_XXFIFOADDR_EP0_END		0x08u

/* RXFIFOSZ/TXFIFOSZ */
#define MUSB_VAL_XXFIFOSZ_16			0x01u
#define MUSB_VAL_XXFIFOSZ_32			0x02u
#define MUSB_VAL_XXFIFOSZ_64			0x03u
#define MUSB_VAL_XXFIFOSZ_128			0x04u
#define MUSB_VAL_XXFIFOSZ_256			0x05u
#define MUSB_VAL_XXFIFOSZ_512			0x06u
#define MUSB_VAL_XXFIFOSZ_1024			0x07u
#define MUSB_VAL_XXFIFOSZ_2048			0x08u
#define MUSB_VAL_XXFIFOSZ_4096			0x09u

#endif /* !_MUSB_REGS_H_ */
