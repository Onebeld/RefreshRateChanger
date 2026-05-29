# RefreshRateChanger
This is a very simple program that changes the screen refresh rate. It's essential if you're using a portable device running OS Windows and your device doesn't support adaptive refresh rate. This means that this program allows you to change the frequency when changing the power mode of your portable device, which helps save battery power.

To run the program, you need to enter the command:
```shell
RefreshRateChanger.exe 144 60
```
where two arguments should specify the screen refresh rate, but the first one specifies the rate when on mains power, and the second one specifies the rate when on battery power.

## Additional features
This program doesn't have any additional functionality. It only changes the refresh rate, if it hasn't already been changed, by checking the power mode. For more options, use the **Task Scheduler**.

Create a task, giving it any name. Add two lines to the triggers: one for user login, and the other for `Kernel-Power` event ID `105` from the `System` log. In the actions, specify the program launch by specifying the full path to this program, and in the optional arguments, specify the screen refresh rate. In the conditions, you need to uncheck the box to disable running only when powered by the mains, so that the task can run regardless of the power source.