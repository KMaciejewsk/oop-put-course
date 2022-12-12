public class Weather {
    private final Forecast forecast;
    private final float temperature;
    public Weather(Forecast a, float b) {
        this.forecast = a;
        this.temperature = b;
    }
    public Weather real_temperature() {
        return new Weather(this.forecast, this.temperature)
    }
    @Override
    public String to_string() {
        return Float.to_string(temperature);
    }
}
