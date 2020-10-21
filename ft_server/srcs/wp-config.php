<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'root' );

/** MySQL database password */
define( 'DB_PASSWORD', '' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '*8oFt-o]M[PG()cBjOl`}rvPv!D2Yt.eu!]$S->o1ggU,1]|Ff4-= Pa{.M(<DN>');
define('SECURE_AUTH_KEY',  '3Ilxs!,Y+fY~wO-mRmp.<5>UG,]vF8#4A@>,F`NT|O<[+nxrG{OJ%.x^MWg->ay>');
define('LOGGED_IN_KEY',    '2Eq4Fx)&DUDVYPrK~fo=Um05:tDWXHqi|)M-e<<K|FiE1N<[hn}C xmUC;9HWM`q');
define('NONCE_KEY',        'k&5s!B6<s=q?o%Q|Yf~vU<@+MA_6ex%~m-J+B|}5~oX+_p~]~24bqzc,*kn=+T8p');
define('AUTH_SALT',        'k1Wbe+Nez.DUp6Z,-vc33e~5V0S`SINA?Ji]U%nKrNLWCvrctLs!}U`f/mZW||]:');
define('SECURE_AUTH_SALT', 'B rk: Je.Ktb+5x~D/pJ{ hz|0,m]2m~^k]}HW;CQ_ !xjD}o,*(+7{DWXrd2i#m');
define('LOGGED_IN_SALT',   '>|lIJk?BU(U~K76BMP_LcS[b+c=tra^d1e7v7B={_Q@7oj+,7C7#,=#|:(6^ZJa@');
define('NONCE_SALT',       'V>f-BxM%/ygF2b4QOHOH%|UN189@OJI9T#!|1h=zkh,{L+^|Lm%lD+~&wc.aDT|A');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';

