scrot -u -d 5 ~/Pictures/Screenshot/%Y-%m-%d-%H-%M-%S.png 
notify-send -u low "Scrot" "Screenshot [window] done !!!" -i ~/.local/share/icons/Papirus-Dark/32x32/devices/camera.svg; paplay ~/.config/catwm/util/screen_capture.wav
