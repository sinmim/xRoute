#ifndef _LICENSING_H_
#define _LICENSING_H_

#include <Arduino.h>
#include <SPIFFS.h>

class RegDev
{
private:
    struct regOptnsData
    {
        String name;
        String generatedKey;
        bool status;
    };

    String filePath;
    File file;
    String logContent;

    String genLis(String secretKey);
    void printStat(regOptnsData &optn);
    String readValueFromString(String str, String keyStr);
    void writeValueToString(String &str, String keyStr, String val);
    void loadLog(regOptnsData &optn);
    void savelog();

public:
    regOptnsData wrkLcns, gyroLcns, humLcns, crntLcns;

    RegDev(String wrkLcnsScrtKey, String gyroLcnsScrtKey, String humLcnsScrtKey, String crntLcnsScrtKey, String path);
    bool openLog();
    bool isActive(regOptnsData &opt);
    bool activate(regOptnsData &optn, String key);
    void deactivate(regOptnsData &optn);
};

// ===== Lizing class
class Leasing
{
private:
    struct UpTime
    {
        String name;
        uint64_t value;
    };

    String filePath;
    File file;
    String logContent;

    void loadUptime(UpTime &t);
    String readValueFromString(String str, String keyStr);
    void writeValueToString(String &str, String keyStr, String val);
    void savelog();

public:
    UpTime uptime;

    Leasing(String path);
    bool openLog();
    uint64_t CountUptimeMinCntr();
    void saveUptime();
    void increaseUpTime();
    uint64_t getUptime();
    void setUptime(uint64_t val);
};

#endif
