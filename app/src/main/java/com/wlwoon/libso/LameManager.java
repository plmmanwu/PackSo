package com.wlwoon.libso;

/**
 * Created by wxy on 2020/7/14.
 */

public class LameManager {
    static {
        System.loadLibrary("lame-3100");
    }

    private volatile static LameManager sLameManager = null;

    public synchronized static LameManager getInstance() {
        if (sLameManager==null) {
            synchronized (LameManager.class) {
                if (sLameManager==null) {
                    sLameManager = new LameManager();
                }
            }
        }
        return sLameManager;
    }

    public native String lameVersion();
}
