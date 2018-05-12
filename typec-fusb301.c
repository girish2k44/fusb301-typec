#include <linux/module.h>
#include <linux/i2c.h>

/******************************************************************************
* Register addresses
******************************************************************************/
#define	DEVICE_ID	0x01
#define	MODES		0x02
#define	CONTROL		0x03
#define	MANUAL		0x04
#define	RESET		0x05
#define	MASK		0x10
#define	STATUS		0x11
#define	TYPE		0x12
#define	INTERRUPT	0x13

/******************************************************************************
* Register bits
******************************************************************************/
/*	R_DEVICE_ID (0x01)	*/
#define ID_REV				0x0F
#define ID_VER_SHIFT		4
#define ID_VER				(0x0F << ID_VER_SHIFT)

/*	R_MODES (0x02)	*/
#define MODE_SRC			0x01
#define MODE_SRC_ACC_SHIFT	1
#define MODE_SRC_ACC			(0x01 << MODE_SRC_ACC_SHIFT)
#define MODE_SNK_SHIFT		2
#define MODE_SNK			(0x01 << MODE_SNK_SHIFT)
#define MODE_SNK_ACC_SHIFT	3
#define MODE_SNK_ACC			(0x01 << MODE_SNK_ACC_SHIFT)
#define MODE_DRP_SHIFT		4
#define MODE_DRP			(0x01 << MODE_DRP_SHIFT)
#define MODE_DRP_ACC_SHIFT	5
#define MODE_DRP_ACC			(0x01 << MODE_DRP_ACC_SHIFT)

/*	R_CONTROL (0x03)	*/
#define CONTROL_INT_MASK		0x01
#define CONTROL_HOST_CUR_SHIFT	1
#define CONTROL_HOST_CUR		(0x03 << CONTROL_HOST_CUR_SHIFT)
#define CONTROL_DRPTOGGLE_SHIFT	4
#define CONTROL_DRPTOGGLE		(0x03 << CONTROL_DRPTOGGLE_SHIFT)

/*	R_MANUAL (0x04)	*/
#define MANUAL_ERROR_REC		0x01
#define MANUAL_DISABLED_SHIFT	1
#define MANUAL_DISABLED			(0x01 << MANUAL_DISABLED_SHIFT)
#define MANUAL_UNATT_SRC_SHIFT	2
#define MANUAL_UNATT_SRC		(0x01 << MANUAL_UNATT_SRC_SHIFT)
#define MANUAL_UNATT_SNK_SHIFT	3
#define MANUAL_UNATT_SNK		(0x01 << MANUAL_UNATT_SNK_SHIFT)

/*	R_RESET (0x05)	*/
#define	SW_RES				0x01

/*    R_MASK (0x10)    */
#define MASK_ATTACH			0x01
#define MASK_DETACH_SHIFT	1
#define MASK_DETACH			(0x01 << MASK_DETACH_SHIFT)
#define MASK_BC_LVL_SHIFT	2
#define MASK_BC_LVL			(0x01 << MASK_BC_LVL_SHIFT)
#define MASK_ACC_CHG_SHIFT	3
#define MASK_ACC_CHG			(0x01 << MASK_ACC_CHG_SHIFT )

/*	R_STATUS (0x11)	*/
#define STATUS_ATTACH			0x01
#define STATUS_BC_LVL_SHIFT	1
#define STATUS_BC_LVL			(0x03 << STAT_BC_LVL_SHIFT)
#define STATUS_VBUS_OK_SHIFT	3
#define STATUS_VBUS_OK			(0x01 << STAT_VBUS_OK_SHIFT)
#define STATUS_ORIENT_SHIFT	4
#define STATUS_ORIENT			(0x03 << STAT_ORIENT_SHIFT)

/*    R_TYPE (0x12)    */
#define TYPE_AUDIO_ACC			0x01
#define TYPE_DBG_ACC_SHIFT	1
#define TYPE_DBG_ACC			(0x01 << TYPE_DBG_ACC_SHIFT)

#ifdef PWR_ACC
#define TYPE_PWR_ACC_SHIFT	2
#define TYPE_PWR_ACC			(0x01 << TYPE_PWR_ACC_SHIFT)
#endif

#define TYPE_SRC_SHIFT		3
#define TYPE_SRC			(0x01 << TYPE_SRC_SHIFT)
#define TYPE_SNK_SHIFT		4
#define TYPE_SNK			(0x01 << TYPE_SNK_SHIFT)

/*    R_INTR (0x13)    */
#define INTR_ATTACH			0x01
#define INTR_DETACH_SHIFT	1
#define INTR_DETACH			(0x01 << INT_DETACH_SHIFT)
#define INTR_BC_LVL_SHIFT	2
#define INTR_BC_LVL			(0x01 << INT_BC_LVL_SHIFT)
#define INTR_ACC_CHG_SHIFT	3
#define INTR_ACC_CHG			(0x01 << INT_ACC_CHG_SHIFT)

/*****************************************************************************/

static int  fusb301_typec_resume(struct i2c_client *client)
{
	return 0;
}

static int  fusb301_typec_suspend(struct i2c_client *client, pm_message_t message)
{
	return 0;
}

static int fusb301_typec_remove(struct i2c_client *client)
{
	return 0;
}

static int fusb301_typec_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	return 0;
}

static const struct i2c_device_id fusb301_typec_i2c_id[] = {
	{ "fusb301", 0 },
	{ }
};

static const struct of_device_id fusb301_typec_id[] = {
		{.compatible = "fusb301"},
		{},
};
MODULE_DEVICE_TABLE(of, fusb301_typec_id);

static struct i2c_driver fusb301_i2c_driver = {
	.driver = {
		.name = "fusb301",
		.of_match_table = of_match_ptr(fusb301_typec_id),
	},
	.probe    = fusb301_typec_probe,
	.remove   = fusb301_typec_remove,
	.suspend  = fusb301_typec_suspend,
	.resume	  = fusb301_typec_resume,
	.id_table = fusb301_typec_i2c_id,
};


static __init int fusb301_i2c_init(void)
{
	return i2c_add_driver(&fusb301_i2c_driver);
}

static __exit void fusb301_i2c_exit(void)
{
	i2c_del_driver(&fusb301_i2c_driver);
}

module_init(fusb301_i2c_init);
module_exit(fusb301_i2c_exit);

MODULE_AUTHOR("girish.sharma@einfochips.com");
MODULE_DESCRIPTION("I2C bus driver for FUSB301 USB Type-C");
MODULE_LICENSE("GPL v2");
