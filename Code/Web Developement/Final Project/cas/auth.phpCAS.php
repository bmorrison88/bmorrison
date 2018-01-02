<?php
// Load the settings from the central config file
require_once $_SERVER['DOCUMENT_ROOT'].'/reserve/cas/config.php';
require_once  $_SERVER['DOCUMENT_ROOT']."/reserve/cas/$phpcas_path" . '/CAS.php';
phpCAS::setDebug();
phpCAS::setVerbose(true);
phpCAS::proxy(CAS_VERSION_2_0, $cas_host, $cas_port, $cas_context);
phpCAS::setCasServerCACert($cas_server_ca_cert_path);

phpCAS::allowProxyChain(
  new CAS_ProxyChain(
    array('https://bookworms.isg.siue.edu/')
  )
);
phpCAS::forceAuthentication();
