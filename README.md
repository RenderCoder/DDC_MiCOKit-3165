# DDC MiCO TcpClient

DeviceDataClerk 模块端程序。修改 uuid 烧录到 MiCOKit 或模块后，配置网络，连接用户口即可使用。

## 修改 uuid 设定

修改`demos/application/wifi_uart/RemoteTcpClient.c`第`129`行：

```c
char *marker = "_你的uuid_";
```

如：

```c
char *marker = "_washmachine1069_";
```

## 编译烧录：
```bash
./make application.wifi_uart@MK3165 download
```