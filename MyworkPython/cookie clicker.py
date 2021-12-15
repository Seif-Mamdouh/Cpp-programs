def loopClick(mouse):
    while(True):
        click(mouse)

def stop(event):
    if (event.KeyID == 27):
        hm.UnhookKeyboard()
        sys.exit("You quit")
