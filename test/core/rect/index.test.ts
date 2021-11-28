import { Rect } from '../../../index'

describe('[core] Rect', () => {
  describe('constructor', () => {
    it('initializes from empty constructor', () => {
      const rect = new Rect()

      expect(rect.x).toStrictEqual(0)
      expect(rect.y).toStrictEqual(0)
      expect(rect.width).toStrictEqual(0)
      expect(rect.height).toStrictEqual(0)
    })

    it('initializes from numbers', () => {
      const rect = new Rect(10, 20, 30, 40)

      expect(rect.x).toStrictEqual(10)
      expect(rect.y).toStrictEqual(20)
      expect(rect.width).toStrictEqual(30)
      expect(rect.height).toStrictEqual(40)
    })
  })

  describe('methods', () => {
    describe('rescale', () => {
      it('rescales from int', () => {
        const rect = new Rect(0, 0, 100, 100)

        rect.rescale(2)

        expect(rect.x).toStrictEqual(0)
        expect(rect.y).toStrictEqual(0)
        expect(rect.width).toStrictEqual(200)
        expect(rect.height).toStrictEqual(200)
      })

      it('rescales from double', () => {
        const rect = new Rect(0, 0, 100, 100)

        rect.rescale(1.5)

        expect(rect.x).toStrictEqual(0)
        expect(rect.y).toStrictEqual(0)
        expect(rect.width).toStrictEqual(150)
        expect(rect.height).toStrictEqual(150)
      })

      it('rescales from double and rounds', () => {
        const rect = new Rect(0, 0, 33, 33)

        rect.rescale(1.5)

        expect(rect.x).toStrictEqual(0)
        expect(rect.y).toStrictEqual(0)
        expect(rect.width).toStrictEqual(49) // 49.5 -> 49
        expect(rect.height).toStrictEqual(49) // 49.5 -> 49
      })
    })
  })
})
