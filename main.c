#include <stdio.h>
#include <windows.h>

int setRefreshRate(int frequency) {
    DEVMODE dm = { 0 };
    dm.dmSize = sizeof(dm);

    if (EnumDisplaySettings(NULL, -1, &dm) == 0)
        return 2;

    if (dm.dmDisplayFrequency == frequency)
        return 1;

    dm.dmDisplayFrequency = frequency;
    dm.dmFields |= DM_DISPLAYFREQUENCY;

    ChangeDisplaySettings(&dm, 0);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2 )
        return -1;

    int acRate = atoi(argv[1]);
    int dcRate = atoi(argv[2]);

    if (acRate == 0 || dcRate == 0)
        return -1;

    SYSTEM_POWER_STATUS status;

    if (GetSystemPowerStatus(&status)) {
        if (status.ACLineStatus == 1)
            return setRefreshRate(acRate);

        return setRefreshRate(dcRate);
    }

    return -2;
}
