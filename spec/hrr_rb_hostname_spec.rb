RSpec.describe HrrRbHostname do
  it "has a version number" do
    expect(HrrRbHostname::VERSION).not_to be nil
  end

  describe ".get" do
    it "returns hostname" do
      expect(HrrRbHostname.get).to eq `hostname`.chomp
    end
  end

  describe ".gethostname" do
    it "returns hostname" do
      expect(HrrRbHostname.gethostname).to eq `hostname`.chomp
    end
  end

  describe ".set" do
    before :example do
      @name_bak = `hostname`.chomp
    end

    after :example do
      `hostname "#{@name_bak}"`
    end

    let(:name){ "new#{@name_bak}" }

    it "sets hostname and returns it" do
      expect(HrrRbHostname.set(name)).to eq name
      expect(`hostname`.chomp).to eq name
    end
  end

  describe ".sethostname" do
    before :example do
      @name_bak = `hostname`.chomp
    end

    after :example do
      `hostname "#{@name_bak}"`
    end

    let(:name){ "new#{@name_bak}" }

    it "sets hostname and returns it" do
      expect(HrrRbHostname.sethostname(name)).to eq name
      expect(`hostname`.chomp).to eq name
    end
  end
end
